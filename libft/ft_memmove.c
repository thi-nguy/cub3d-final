/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:42:49 by thi-nguy          #+#    #+#             */
/*   Updated: 2019/11/26 16:10:30 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	if (dest != (void *)0 || src != (void *)0)
	{
		if (src < dest)
		{
			i = len;
			while (i-- > 0)
				d[i] = s[i];
		}
		else
		{
			i = 0;
			while (i < len)
			{
				d[i] = s[i];
				i++;
			}
		}
	}
	return (dest);
}
