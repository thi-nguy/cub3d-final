/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:37:50 by thi-nguy          #+#    #+#             */
/*   Updated: 2019/12/11 15:16:44 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(tab = (char *)malloc(sizeof(char) * \
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i] != 0)
		{
			tab[i] = s1[i];
			i++;
		}
		while (s2[j] != 0)
		{
			tab[i + j] = s2[j];
			j++;
		}
		tab[i + j] = '\0';
		return (tab);
	}
	return (NULL);
}
