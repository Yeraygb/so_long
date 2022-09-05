/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:36:30 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/04 12:34:38 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *savebuf)
{
	ssize_t	nr_bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nr_bytes = 1;
	while (!ft_strchr(savebuf, '\n') && nr_bytes != 0)
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free (buf);
			return (NULL);
		}
		if (nr_bytes == 0)
			break ;
		buf[nr_bytes] = '\0';
		savebuf = ft_strjoin(savebuf, buf);
	}
	free (buf);
	return (savebuf);
}

int	line_jump(char *savebuf)
{
	int		i;

	i = 0;
	while (savebuf[i])
	{
		if (savebuf[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

char	*ft_substr_line(char *savebuf)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	n = line_jump(savebuf);
	if (!savebuf[i])
		return (NULL);
	str = (char *)malloc(sizeof(char) * (n + 2));
	if (!str)
		return (NULL);
	while (savebuf[i] && savebuf[i] != '\n')
	{
		str[i] = savebuf[i];
		i++;
	}
	if (savebuf[i] == '\n')
	{
		str[i] = savebuf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr_static(char *s)
{
	char	*str;
	size_t	j;
	size_t	n;

	n = line_jump(s);
	if (!s[n])
	{
		free (s);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - n + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[n])
		str[j++] = s[n++];
	str[j] = '\0';
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*savebuf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savebuf = ft_read(fd, savebuf);
	if (!savebuf)
	{
		free (savebuf);
		return (NULL);
	}
	line = ft_substr_line(savebuf);
	savebuf = ft_substr_static(savebuf);
	return (line);
}

int main()
{
	ssize_t	fd = open("test1.txt", O_RDONLY);
	size_t	i = 3;
	char	*line;

	while (i--)
	{
		line = get_next_line(fd);
		printf("line %zu = %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
