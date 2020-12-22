/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:39:45 by thi-nguy          #+#    #+#             */
/*   Updated: 2019/12/09 13:22:23 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	if (!f)
// 		return ;
// 	while (lst)
// 	{
// 		(*f)(lst->content);
// 		lst = lst->next;
// 	}
// }

// Version using in cub3d
void	ft_lstiter(t_list *lst, int (*f)(const char *, ...))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		(*f)("\n");
		lst = lst->next;
	}
}
