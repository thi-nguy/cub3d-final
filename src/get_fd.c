/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:54:10 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:54:58 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_fd(char *arg, t_info *info)
{
	info->fd = open(arg, O_RDONLY);
	if (info->fd <= 0)
	{
		ft_putstr_fd("Error while opening file.\n", 1);
		exit(ERROR);
	}
}
