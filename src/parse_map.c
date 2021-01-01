#include "cub3d.h"

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
    // printf("g_count_player = %i\n", g_count_player);
    return (SUCCESS);
}

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