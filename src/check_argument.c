/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:11:49 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 09:42:53 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	check_extension(char **av)
{
	if (check_format(av[1], &extension_name) == ERROR)
	{
		ft_putstr_fd("The file format should be '.cub'.\n", 1);
		exit(ERROR);
	}
}

void	check_argument(int ac, char **av, int *save)
{
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save") == ERROR)
		{
			ft_putstr_fd("The second argument should be '--save'.\n", 1);
			exit(ERROR);
		}
		else
		{
			*save = 1;
			check_extension(av);
		}
	}
	else if (ac == 2)
		check_extension(av);
	else
	{
		ft_putstr_fd("The number of arguments is not correct.\n", 1);
		exit(ERROR);
	}
}
