/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:44:50 by ygonzale          #+#    #+#             */
/*   Updated: 2022/06/29 16:15:43 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

check_errors(int argc, char **argv)
{
	int i;

	if (!argc == 2)
	{
		printf("Number of argument invalid\n");
		exit(0);
	}
}
