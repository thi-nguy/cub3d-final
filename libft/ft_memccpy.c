/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:57:53 by thi-nguy          #+#    #+#             */
/*   Updated: 2019/11/19 13:08:17 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char const	*src_cpy;
	unsigned char		*dst_cpy;

	src_cpy = src;
	dst_cpy = dst;
	while (n-- > 0)
	{
		*dst_cpy = *src_cpy;
		if (*dst_cpy == (unsigned char)c)
			return (dst_cpy + 1);
		++dst_cpy;
		++src_cpy;
	}
	return (NULL);
}
