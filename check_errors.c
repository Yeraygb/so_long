/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:44:50 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/01 11:09:15 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Number of argument invalid\n", 2);
		exit(0);
	}
}
