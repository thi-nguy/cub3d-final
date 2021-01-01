#include "cub3d.h"

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
                info->player_start_angle = g_grid_array[i][j];
            }
            j++;
        }
        i++;
    }
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

