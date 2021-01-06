/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:01:13 by thi-nguy          #+#    #+#             */
/*   Updated: 2019/12/11 16:03:10 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (src[a] != '\0' && a < n)
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		s;
	size_t		len;
	char		*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s = 0;
	while (s1[s] && ft_strchr(set, s1[s]) != NULL)
		s++;
	len = ft_strlen(&s1[s]);
	if (len != 0)
		while (s1[s + len - 1]
				&& ft_strchr(set, s1[s + len - 1]) != NULL)
			len--;
	if ((trim = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	trim = ft_strncpy(trim, &s1[s], len);
	trim[len] = '\0';
	return (trim);
}
