/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:36:39 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:40:08 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array, int len)
{
	int i;

	if (!array)
		return ;
	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int		free_memory(t_info *info, int return_code)
{
	if (info->head_llist)
		ft_lstclear(&info->head_llist, free);
	return (return_code);
}
