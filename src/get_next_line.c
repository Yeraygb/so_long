/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:16:28 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/13 10:16:38 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#define BUFFER_SIZE 42

char	*ft_read_buffer_nl(char *str, int fd, size_t *bytes_read)
{
	char	*aux;
	char	buffer[BUFFER_SIZE + 1];

	aux = ft_strjoin(str, "");
	while (*bytes_read > 0 && ft_strnl(aux) == -1)
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((int)*bytes_read <= 0)
		{
			if ((int)*bytes_read == 0)
				return (aux);
			free(aux);
			return (NULL);
		}
		buffer[*bytes_read] = '\0';
		if (!aux)
			aux = ft_substr(buffer, 0, BUFFER_SIZE);
		else
			aux = ft_strjoin(aux, buffer);
	}
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*aux;
	char		*line;
	size_t		bytes_read;

	bytes_read = BUFFER_SIZE;
	aux = ft_strjoin(str, "");
	str = NULL;
	if (fd == -1)
		return (NULL);
	aux = ft_read_buffer_nl(aux, fd, &bytes_read);
	if (!aux)
		return (NULL);
	line = ft_substr(aux, 0, ft_strnl(aux));
	str = ft_substr(aux, ft_strnl(aux), ft_strlen(aux));
	if (bytes_read <= 0)
		free(str);
	free(aux);
	return (line);
}
