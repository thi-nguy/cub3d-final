/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_wall_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:27:23 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 12:32:07 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_no_path(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "NO")))
	{
		ft_putstr_fd("Error\nCannot find the NO's path or
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
	g_no_path = ft_strdup(line[1]);
	free_array(line, 2);
	return (SUCCESS);
}

int		parse_so_path(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "SO")))
	{
		ft_putstr_fd("Error\nCannot find the SO's path or
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
	g_SO_path = ft_strdup(line[1]);
	free_array(line, 2);
	return (SUCCESS);
}

int		parse_we_path(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "WE")))
	{
		ft_putstr_fd("Error\nCannot find the WE's path or
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
	g_WE_path = ft_strdup(line[1]);
	free_array(line, 2);
	return (SUCCESS);
}

int		parse_ea_path(t_list **lst)
{
	t_list	*node;
	char	**line;

	if (!(node = get_node(lst, "EA")))
	{
		ft_putstr_fd("Error\nCannot find the EA's path or
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
	g_EA_path = ft_strdup(line[1]);
	free_array(line, 2);
	return (SUCCESS);
}

void	put_wall_texture_into_array(void)
{
	g_texture[0].path = ft_strdup(g_no_path);
	g_texture[1].path = ft_strdup(g_so_path);
	g_texture[2].path = ft_strdup(g_we_path);
	g_texture[3].path = ft_strdup(g_ea_path);
}
