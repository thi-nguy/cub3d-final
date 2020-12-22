#include "cub3d.h"

void    get_fd(char* arg, t_info* info)
{
    info->fd = open(arg, O_RDONLY);
    
    if (info->fd <= 0)
    {
        ft_putstr_fd("Error while opening file.\n", 1);
        exit(ERROR);
    }
}