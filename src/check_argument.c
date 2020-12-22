#include "cub3d.h"

int		check_format(char *av, char *format)
{
	int		av_l;
	int		format_l;

	av_l = ft_strlen(av);
	format_l = ft_strlen(format);
	if (av_l < format_l)
		return (ERROR);
	else
		return (ft_strcmp(av + av_l - format_l, format));
}

void    check_argument(int ac, char** av, int* save)
{
    if(ac == 3)
    {
        if(ft_strcmp(av[2], "--save") == ERROR)
        {
            ft_putstr_fd("The second argument should be '--save'.\n", 1);
            exit(ERROR);
        }
        else
        {
            *save = 1;
            if (check_format(av[1], ".cub") == ERROR)
            {
                ft_putstr_fd("The file format should be '.cub'.\n", 1);
                exit(ERROR);
            }
        }
    }
    else if (ac == 2)
    {
        if (check_format(av[1], ".cub") == ERROR)
            {
                ft_putstr_fd("The file format should be '.cub'.\n", 1);
                exit(ERROR);
            }
    }
    else
    {
        ft_putstr_fd("The number of arguments is not correct.\n", 1);
        exit(ERROR);
    }
}