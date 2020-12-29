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
        return (c);// - 48;
    else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
    {
        g_count_player++;
        if (g_count_player > 1)
        {
            ft_putstr_fd("Error\nThere are more than one player\n", 1);
            return (ERROR);
        }
        return (c);
    }
    else if (ft_isspace(c))
        return(43); // +
    else
        return (ERROR); // g_grid_array[i][j] = 37; // %

}

int check_copy_map_element_into_array(t_list *map_lst, int row, int col)
{
    int i;
    int j;
    // static int *count_player;
    char *line;
    t_list *tmp;

    i = 0;
    g_count_player = 0;
    tmp = map_lst;
    line = (char*)tmp->content;
    while(line && i < row)
    {
        j = 0;
        while (j < col)
        {
            g_grid_array[i][j] = check_valid_element(line[j]);
            if (g_grid_array[i][j] == ERROR)
            {
                if (g_count_player == 1)
                    ft_putstr_fd("Error\nMap's elements are not valid.\n", 1);
                return (ERROR);//, count_player);
            }
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
        return (ERROR);
    
    int i = 0;
    int j;
    while (i < row)
    {
        j = 0;
        while(j < col)
        {
            printf("%c", g_grid_array[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }





    return (SUCCESS);


}


int parse_map(t_info* info)
{
    if (get_row_column(&info->head_llist, &info->map_row, &info->map_col) == ERROR)
        return(free_memory(info, ERROR));
    if (put_map_in_array(&info->head_llist, info->map_row, info->map_col) == ERROR)
        return (free_memory(info, ERROR));
        
    return(SUCCESS);
}