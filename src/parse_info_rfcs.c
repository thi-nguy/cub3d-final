/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_rfcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:55:43 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:56:53 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_resolution(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "R")))
	{
		ft_putstr_fd("Error\nCannot find the resolution or
				misconfiguration.\n", 1);
		return (ERROR);
	}
	if (check_number_of_element(node->content, 3) == ERROR)
		return (ERROR);
	line = ft_split(node->content, ' ');
	g_window.width = ft_atoi(line[1]);
	g_window.height = ft_atoi(line[2]);
	if (g_window.width <= 0 || g_window.height <= 0)
	{
		ft_putstr_fd("Error\nWindow size is
				misconfiguration.\n", 1);
		free_array(line, 3);
		return (ERROR);
	}
	free_array(line, 3);
	return (SUCCESS);
}

int	parse_floor_color(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "F")))
	{
		ft_putstr_fd("Error\nCannot find the floor color or
				misconfiguration.\n", 1);
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

int	parse_ceiling_color(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "C")))
	{
		ft_putstr_fd("Error\nCannot find the ceiling color or
				misconfiguration.\n", 1);
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

int	parse_sprite_path(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "S")))
	{
		ft_putstr_fd("Error\nCannot find the Sprite or
				misconfiguration.\n", 1);
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
