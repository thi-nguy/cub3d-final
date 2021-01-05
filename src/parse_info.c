#include "cub3d.h"

int parse_resolution(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "R")))
    {
        ft_putstr_fd("Error\nCannot find the resolution or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 3) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    g_window.width = ft_atoi(line[1]);
    g_window.height = ft_atoi(line[2]);
    if (g_window.width <= 0 || g_window.height <= 0)
    {
        ft_putstr_fd("Error\nWindow size is misconfiguration.\n", 1);
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
        ft_putstr_fd("Error\nCannot find the floor color or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element_color(node->content + 2, 3) == ERROR)
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
        ft_putstr_fd("Error\nCannot find the ceiling color or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element_color(node->content + 2, 3) == ERROR)
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

int parse_sprite_path(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "S")))
    {
        ft_putstr_fd("Error\nCannot find the Sprite or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 2) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    if (check_format(line[1], ".xpm") == ERROR)
        {
            ft_putstr_fd("Error\nThe file format should be '.xpm'.\n", 1);
            free_array(line, 2);
            exit(ERROR);
        }
    g_sprite.path = ft_strdup(line[1]);
    free_array(line, 2);
    return (SUCCESS);
}


int parse_NO_path(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "NO")))
    {
        ft_putstr_fd("Error\nCannot find the NO's path or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 2) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    if (check_format(line[1], ".xpm") == ERROR)
        {
            ft_putstr_fd("Error\nThe file format should be '.xpm'.\n", 1);
            free_array(line, 2);
            exit(ERROR);
        }
    g_NO_path = ft_strdup(line[1]);

    free_array(line, 2);
    return (SUCCESS);
}

int parse_SO_path(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "SO")))
    {
        ft_putstr_fd("Error\nCannot find the SO's path or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 2) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    if (check_format(line[1], ".xpm") == ERROR)
        {
            ft_putstr_fd("Error\nThe file format should be '.xpm'.\n", 1);
            free_array(line, 2);
            exit(ERROR);
        }
    g_SO_path = ft_strdup(line[1]);
    free_array(line, 2);
    return (SUCCESS);
}

int parse_WE_path(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "WE")))
    {
        ft_putstr_fd("Error\nCannot find the WE's path or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 2) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    if (check_format(line[1], ".xpm") == ERROR)
        {
            ft_putstr_fd("Error\nThe file format should be '.xpm'.\n", 1);
            free_array(line, 2);
            exit(ERROR);
        }
    g_WE_path = ft_strdup(line[1]);
    free_array(line, 2);
    return (SUCCESS);
}

int parse_EA_path(t_list** lst)
{
    t_list* node;
    char** line;

    if (!(node = get_node(lst, "EA")))
    {
        ft_putstr_fd("Error\nCannot find the EA's path or misconfiguration.\n", 1);
        return (ERROR);
    }
    if (check_number_of_element(node->content, 2) == ERROR)
        return (ERROR);
    line = ft_split(node->content, ' ');
    if (check_format(line[1], ".xpm") == ERROR)
        {
            ft_putstr_fd("Error\nThe file format should be '.xpm'.\n", 1);
            free_array(line, 2);
            exit(ERROR);
        }
    g_EA_path = ft_strdup(line[1]);
    free_array(line, 2);
    return (SUCCESS);
}

void    put_wall_texture_into_array(void)
{
    g_texture[0].path = ft_strdup(g_NO_path);
    g_texture[1].path = ft_strdup(g_SO_path);
    g_texture[2].path = ft_strdup(g_WE_path);
    g_texture[3].path = ft_strdup(g_EA_path);
}

int parse_info(t_info* info)
{
    if (parse_resolution(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    if (parse_floor_color(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    if (parse_ceiling_color(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    if (parse_sprite_path(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    if (parse_NO_path(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    if (parse_SO_path(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    if (parse_WE_path(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    if (parse_EA_path(&info->head_llist) == ERROR)
        return(free_memory(info, ERROR));
    
    return(SUCCESS);
}
