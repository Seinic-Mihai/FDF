/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:17:38 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/19 11:43:28 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	menu(void)
{
	ft_putstr("\n\n\n\n\n\n\n\033[0;32mKeys menu:\033[0m\n");
	ft_putstr("\033[0;33m\n\n\n(1): \"+\" -> Zoom in.\n");
	ft_putstr("(2): \"-\" -> Zoom out.\n");
	ft_putstr("(3): \"Key Right\" -> Move object to right.\n");
	ft_putstr("(4): \"Key Left\" -> Move object to left.\n");
	ft_putstr("(5): \"Key Up\" -> Move object up.\n");
	ft_putstr("(6): \"Key Down\" -> Move object down.\n");
	ft_putstr("(7): \"Key page up\" -> Increase the Z coordinates.\n");
	ft_putstr("(8): \"Key page down\" -> Decrease the Z coordinates.\n");
	ft_putstr("(9): \"Num: 6\" -> Rotate left.\n");
	ft_putstr("(10): \"Num: 4\" -> Rotate right.\n");
	ft_putstr("(11): \"1\" -> Upper view without colors of Z.\n");
	ft_putstr("(12): \"2\" -> Isometric view and initializing.\n\033[0m");
	ft_putstr("\033[1;91m(13): \"esc\" -> Quiting.\n\033[0m");
}
