/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:51:21 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/16 13:00:38 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_ex(void)
{
	ft_putstr("\033[0;33m\nPlease give a valid file.\033[0m");
	ft_putstr("\n\n\033[0;32mExample:\033[0m\n0 0 1\n0 0 1\n1 1 1\n");
}
