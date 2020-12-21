/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:31 by thi-nguy          #+#    #+#             */
/*   Updated: 2019/11/26 15:01:39 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_char;
	char		*dst_char;

	if (dst != (void *)0 || src != (void *)0)
	{
		src_char = (char *)src;
		dst_char = (char *)dst;
		while (n > 0)
		{
			*dst_char = *src_char;
			dst_char++;
			src_char++;
			n--;
		}
	}
	return (dst);
}
