/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:00:42 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/27 11:55:47 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		get_x_y(char *str, int *x, int *y)
{
	while (str != NULL)
	{
		if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
				str++;
			(*x)++;
		}
		if (*str < '0' || *str > '9')
		{
			while ((*str < '0' || *str > '9') && *str != '\0')
				str++;
		}
		if (*str == '\0')
			str = NULL;
	}
	(*y)++;
}

int			get_x(char *str)
{
	int		x;

	x = 0;
	while (str != NULL)
	{
		if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
				str++;
			x++;
		}
		if (*str < '0' || *str > '9')
		{
			while ((*str < '0' || *str > '9') && *str != '\0')
				str++;
		}
		if (*str == '\0')
			str = NULL;
	}
	return (x);
}
