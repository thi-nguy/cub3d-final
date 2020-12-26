#include "cub3d.h"



int read_line_into_linked_list(t_list** head_llist, int fd)
{
    char* line;
    t_list* new_node;
    int return_get_next_line;

    return_get_next_line = 1;

    while(return_get_next_line)
    {
        if ((return_get_next_line = get_next_line(fd, &line)) == -1)
        {
            ft_putstr_fd("Error while reading each line of the file.\n", 1);
            return(ERROR);
        }
        if (!(new_node = ft_lstnew(line)))
            return(ERROR);
        ft_lstadd_back(head_llist, new_node);
    }
    if (close(fd) != 0)
        return (ERROR);
    return (SUCCESS);
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

int     parse(t_info* info)
{
    if (read_line_into_linked_list(&info->head_llist, info->fd) == ERROR)
        return (ERROR);
    if (parse_info(info) == ERROR)
         return(ERROR);
    // if (parse_map(info) == ERROR)
    //     return (ERROR);
    return (SUCCESS);
}