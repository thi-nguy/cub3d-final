/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:35:51 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 12:41:28 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

int	line_is_map(char *line)
{
	if (((*line == 'R' || *line == 'F' || *line == 'C' || *line == 'S')
				&& *(line + 1) == ' '))
		return (0);
	if (*line == 'N' || *line == 'E' || *line == 'W' ||
			ft_strncmp(line, "SO", 2) == 0)
		return (0);
	if (!(*line))
		return (0);
	return (1);
}

int	get_size_node(t_list *lst)
{
	int	size;
	int	max_size;

	max_size = -1;
	while (lst->next != NULL)
	{
		size = (int)ft_strlen(lst->content);
		if (size > max_size)
			max_size = size;
		lst = lst->next;
	}
	return (max_size);
}

int	**alloc_memory(int row, int col)
{
	int **new_array;
	int i;

	i = -1;
	if (!(new_array = malloc(sizeof(int*) * row)))
		return (NULL);
	while (++i < row)
	{
		if (!(new_array[i] = malloc(sizeof(int) * col)))
		{
			while (--i >= 0)
			{
				free(new_array[i]);
				new_array = NULL;
			}
			return (NULL);
		}
	}
	return (new_array);
}

int	**copy_map_grid(int map_row, int map_col)
{
	int **tmp;
	int a;
	int b;

	tmp = malloc(sizeof(int *) * map_row);
	a = 0;
	while (a < map_row)
	{
		tmp[a] = malloc(sizeof(int) * map_col);
		a++;
	}
	a = 0;
	while (a < map_row)
	{
		b = 0;
		while (b < map_col)
		{
			tmp[a][b] = g_grid_array[a][b];
			b++;
		}
		a++;
	}
	return (tmp);
}
