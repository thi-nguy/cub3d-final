/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:23:36 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 12:27:07 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			find_item(const char *content, char *x)
{
	int len_x;
	int result_after_char;

	len_x = ft_strlen(x);
	result_after_char = ft_strncmp(content + len_x, " ", 1);
	if (ft_strncmp(content, x, len_x) == 0 && result_after_char == 0)
		return (1);
	return (0);
}

t_list		*ft_lstfind(t_list *lst, char *item, int f(const char *, char *))
{
	t_list *tmp;
	t_list *prev;

	tmp = lst;
	if (!f)
		return (ERROR);
	while (lst)
	{
		if ((f)(lst->content, item) == 1)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

t_list		*get_node(t_list **llist, char *item)
{
	t_list *found_node;

	found_node = ft_lstfind(*llist, item, find_item);
	if (!found_node)
		return (NULL);
	if (found_node == ft_lstlast(*llist))
		return (NULL);
	return (found_node);
}

int			check_number_of_element(char *line, int num)
{
	int num_of_element;

	num_of_element = ft_count_words(line, ' ');
	if (num_of_element == num)
		return (SUCCESS);
	else
	{
		ft_putstr_fd("Error.\n", 1);
		ft_putstr_fd("Number of elements is not correct.\n", 1);
		return (ERROR);
	}
}

int			check_number_of_element_color(char *line, int num)
{
	int num_of_element;

	num_of_element = ft_count_words(line, ',');
	if (num_of_element == num)
		return (SUCCESS);
	else
	{
		ft_putstr_fd("Error.\n", 1);
		ft_putstr_fd("Number of elements is not correct.\n", 1);
		return (ERROR);
	}
}
