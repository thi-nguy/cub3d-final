/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:35:37 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/02/11 13:03:55 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_str(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(dst = (char*)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2[++i])
		dst[len1 + i] = s2[i];
	dst[len1 + i] = '\0';
	return (dst);
}

int		find_n(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_line(char **str, char **line, int i)
{
	*line = ft_substr(*str, 0, i);
	if (*line == 0)
		return (-1);
	if (!(ft_strcpy(*str, *str + i + 1)))
		return (-1);
	if (**str == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*rest = NULL;
	int				byte_read;
	int				i;

	if (!line || read(fd, buff, 0) < 0) // tại sao là 0? Vi chi doc xem co ok khong chua bat dau doc.
		return (-1);
	if (rest && (((i = find_n(rest, '\n')) != -1)))
		return (get_line(&rest, line, i));
	while (((byte_read = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[byte_read] = '\0';
		rest = join_str(rest, buff);
		if (((i = find_n(rest, '\n')) != -1))
			return (get_line(&rest, line, i));
	}
	if (rest)
	{
		*line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (byte_read);
	}
	*line = ft_strdup("");
	return (byte_read);
}
