/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:44:29 by ygonzale          #+#    #+#             */
/*   Updated: 2022/06/29 13:35:56 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

/*
** Reserva y devuelve una nueva string,
** formada por la concatenación de ’s1’ y ’s2’.
**
** @param {char const s1} Primera string
** @param {char const s2} Segunda string
** 
** @return {char *} La string concatenada resultante
*/
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	n = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

/*
** Funcion busca el primer caracter que coincide en 2 strings
**
** @param {const char *s} La string en la que se quiere buscar un parametro
** @param {int c} El parametro que quieres buscar
**
** @return {char} La direc de la *s desde que ha encontrado la 1º coincidencia
*/
char	*ft_strchr_gnl(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[i]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
