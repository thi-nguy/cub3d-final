/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:32:32 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 12:49:47 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*get_first_line_map(t_list **lst)
{
	t_list	*found_node;
	t_list	*tmp;
	char	*line;

	tmp = *lst;
	if (!*lst)
		return (ERROR);
	while (tmp)
	{
		if (line_is_map(tmp->content) == 1)
			break ;
		tmp = tmp->next;
	}
	found_node = tmp;
	line = (char*)tmp->content;
	if (*(line + skip_space(line)) != '1')
		return (ERROR);
	return (tmp);
}

int		put_map_in_array(t_list **lst, int row, int col)
{
	t_list *map_llist;

	if (!(map_llist = get_first_line_map(lst)))
	{
		ft_putstr_fd("Error\nCannot find the start of map or
				misconfiguration.\n", 1);
		return (ERROR);
	}
	if (!(g_grid_array = alloc_memory(row, col)))
	{
		ft_putstr_fd("Error\nCannot allocate memory.\n", 1);
		return (ERROR);
	}
	if (check_copy_map_element_into_array(map_llist, row, col) == ERROR)
	{
		if (g_count_player == 0)
			ft_putstr_fd("Error\nThere should be at least one player.\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

int		get_row_column(t_list **lst, int *row, int *col)
{
	t_list *map_llist;

	if (!(map_llist = get_first_line_map(lst)))
	{
		ft_putstr_fd("Error\nCannot find the start of map or
				map is invalid.\n", 1);
		return (ERROR);
	}
	if ((*row = ft_lstsize(map_llist)) < 3)
	{
		ft_putstr_fd("Error\nNumber of line is too small\n", 1);
		return (ERROR);
	}
	if ((*col = get_size_node(map_llist)) < 3)
	{
		ft_putstr_fd("Error\nNumber of column is too small\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

int		parse_map(t_info *info)
{
	if (get_row_column(&info->head_llist, &info->map_row,
				&info->map_col) == ERROR)
		return (free_memory(info, ERROR));
	if (put_map_in_array(&info->head_llist, info->map_row,
				info->map_col) == ERROR)
		return (free_memory(info, ERROR));
	get_player_position(info, info->map_row, info->map_col);
	if (check_if_map_close(info) == ERROR)
		return (free_memory(info, ERROR));
	return (SUCCESS);
}
