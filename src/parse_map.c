#include "cub3d.h"

int get_row_column(t_list **lst, int *row, int *col)
{
    t_list* map_llist;

    if (!(map_llist = get_first_line_map(lst))) 
    {
        ft_putstr_fd("Error\nCannot find the start of map or map is invalid.\n", 1);
        return (ERROR);
    }
    if ((*row = ft_lstsize(map_llist)) < 3)
    {
		ft_putstr_fd("Error\nNumber of line is too small\n", 1);
		return (ERROR);
	}
    if ((*col = get_size_node(map_llist)) < 3)
	{
		ft_putstr_fd("Error\nNumber of column is too small\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

int** alloc_memory(int row, int col)
{
    int** new_array;
    int i;

    i = -1;
    if (!(new_array = malloc(sizeof(int*) * row)))
		return (NULL);
    while(++i < row)
    {
	    if (!(new_array[i] = malloc(sizeof(int) * col)))
        {
            while (--i >= 0)
            {
                free(new_array[i]);
                new_array = NULL;
            }
            return (NULL);
        }    
    }
    return (new_array);
}

char    check_valid_element(char c)
{
    // static int count;
    
    // count = 0;
    if (!c)
        return (35);// 35 : #
    else if (c == '0' || c == '1' || c == '2')
        return (c - 48);
    else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
    {
        g_count_player++;
        if (g_count_player > 1)
        {
            ft_putstr_fd("Error\nNumber of player is more than one.\n", 1);
            return (VALID_ERROR);
        }
        return (c);
    }
    else if (ft_isspace(c))
        return(43); // +
    else
    {
        ft_putstr_fd("Error\nMap's elements are not valid.\n", 1);
        return (VALID_ERROR); //g_grid_array[i][j] = 37; // %
    }
}

int check_copy_map_element_into_array(t_list *map_lst, int row, int col)
{
    int i;
    int j;
    char *line;
    t_list *tmp;

    i = 0;
    tmp = map_lst;
    line = (char*)tmp->content;
    while(line && i < row)
    {
        j = 0;
        while (j < col)
        {
            g_grid_array[i][j] = check_valid_element(line[j]);
            if (g_grid_array[i][j] == VALID_ERROR)
                return (ERROR);//, count_player);
            j++;
        }
        i++;
        tmp = tmp->next;
        if (tmp != NULL)
            line = (char*)tmp->content;
    }
    return (SUCCESS);
}

int put_map_in_array(t_list **lst, int row, int col)
{
    t_list* map_llist;

    if (!(map_llist = get_first_line_map(lst))) 
    {
        ft_putstr_fd("Error\nCannot find the start of map or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (!(g_grid_array = alloc_memory(row, col)))
    {
        ft_putstr_fd("Error\nCannot allocate memory.\n", 1);
        return (ERROR);
    }
    if (check_copy_map_element_into_array(map_llist, row, col) == ERROR)
        {
            if (g_count_player == 0)
                ft_putstr_fd("Error\nThere should be at least one player.\n", 1);
            return (ERROR);
        }
    // Check map
    int i = 0;
    int j;
    while (i < row)
    {
        j = 0;
        while(j < col)
        {
            printf("%i", g_grid_array[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("g_count_player = %i\n", g_count_player);
    return (SUCCESS);
}



void     get_player_position(t_info *info, int row, int col)
{
    int i;
    int j;

    i = 0;
    while (i < row)
    {
        j = 0;
        while (j < col)
        {
            if (g_grid_array[i][j] == 'N' || g_grid_array[i][j] == 'S' || g_grid_array[i][j] == 'W' || g_grid_array[i][j] == 'E')
            {
                info->player_start_x = i;
                info->player_start_y = j;
            }
            j++;
        }
        i++;
    }
}

int **copy_map_grid(int map_row, int map_col)
{
    int **tmp;
    int a;
    int b;

   tmp = malloc(sizeof(int *) * map_row);
    a = 0;
    while (a < map_row)
    {
        tmp[a] = malloc(sizeof(int) * map_col);
        a++;
    }
    a = 0;
    while (a < map_row)
    {
        b = 0;
        while (b < map_col)
        {
            tmp[a][b] = g_grid_array[a][b];
            b++;
        }
        a++;
    }
    return (tmp);
}

int flood_fill(int **map_copy, int map_row, int map_col, int row, int col, int i)
{
    if (row < 0 || row >= map_row || col < 0 || col >= map_col)
		return (i);
	else if (map_copy[row][col] == 1)
		return (0);
    else if (map_copy[row][col] == 43) //space
        return (VALID_ERROR);
	map_copy[row][col] = 1;
	// return (flood_fill(map_copy, map_row, map_col, row - 1, col - 1, 0) +
	// 		flood_fill(map_copy, map_row, map_col, row - 1, col + 1, 0) +
	// 		flood_fill(map_copy, map_row, map_col, row + 1, col - 1, 0) +
	// 		flood_fill(map_copy, map_row, map_col, row + 1, col + 1, 0) +
	return(flood_fill(map_copy, map_row, map_col, row - 1, col, 1) +
			flood_fill(map_copy, map_row, map_col, row + 1, col, 1) +
			flood_fill(map_copy, map_row, map_col, row, col - 1, 1) +
			flood_fill(map_copy, map_row, map_col, row, col + 1, 1));
}

int check_if_map_close(t_info *info)
{
    int borken_wall;
    int **tmp;

    tmp = copy_map_grid(info->map_row, info->map_col); //free sau day
    borken_wall = 0;
    borken_wall = flood_fill(tmp, info->map_row, info->map_col, info->player_start_x, info->player_start_y, 0);
    free_array((char**)tmp, info->map_row);
    tmp = NULL;
    if(borken_wall > 0)
    {
        ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 1);
        return (ERROR);
    }
    else if (borken_wall == VALID_ERROR)
    {
        ft_putstr_fd("Error.\nInside map has empty space.\n", 1);
        return (ERROR);
    }
    return (SUCCESS);
}

int parse_map(t_info* info)
{
    if (get_row_column(&info->head_llist, &info->map_row, &info->map_col) == ERROR)
        return(free_memory(info, ERROR));
    if (put_map_in_array(&info->head_llist, info->map_row, info->map_col) == ERROR)
        return (free_memory(info, ERROR));
    get_player_position(info, info->map_row, info->map_col);
    if (check_if_map_close(info) == ERROR)
        return (free_memory(info, ERROR));

        
    return(SUCCESS);
}