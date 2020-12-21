/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:37:03 by thi-nguy          #+#    #+#             */
/*   Updated: 2019/11/19 17:29:51 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *pos;

	pos = (0);
	while (*s)
	{
		if (*s == c)
			pos = (char *)s;
		++s;
	}
	if (pos)
		return (pos);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
