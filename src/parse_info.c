#include "cub3d.h"

int parse_resolution(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "R")))
    {
        ft_putstr_fd("Error\n", 1);
        ft_putstr_fd("Cannot find the resolution or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 3) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    g_window_width = ft_atoi(line[1]);
    g_window_height = ft_atoi(line[2]);
    if (g_window_height <= 0 || g_window_width <= 0)
    {
        ft_putstr_fd("Error\n", 1);
        ft_putstr_fd("Window size is misconfiguration.\n", 1);
        free_array(line, 3);
        return (ERROR);
    }
    free_array(line, 3);
    return (SUCCESS);
}


int parse_floor_color(t_list** lst)
{
     t_list* node;
    char** line;

     if (!(node = get_node(lst, "F")))
    {
        ft_putstr_fd("Error\n", 1);
        ft_putstr_fd("Cannot find the floor color or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 4) == ERROR)
        return (ERROR);
    line = ft_split(node->content + 2, ',');
    if ((g_floor_color = get_rgb_int(line)) == -1)
    {
        free_array(line, 3);
        return (ERROR);
    }
    free_array(line, 3);
    return (SUCCESS);
}

int parse_ceiling_color(t_list** lst)
{
     t_list* node;
    char** line;

     if (!(node = get_node(lst, "C")))
    {
        ft_putstr_fd("Error\n", 1);
        ft_putstr_fd("Cannot find the ceiling color or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 4) == ERROR)
        return (ERROR);
    line = ft_split(node->content + 2, ',');
    if ((g_ceiling_color = get_rgb_int(line)) == -1)
    {
        free_array(line, 3);
        return (ERROR);
    }
    free_array(line, 3);
    return (SUCCESS);
}

