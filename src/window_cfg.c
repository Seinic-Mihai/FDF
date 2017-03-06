/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_cfg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 11:22:20 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/19 11:34:36 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	window_cfg(t_env *env)
{
	int x;
	int y;

	x = WIN_MAX_X;
	y = WIN_MAX_Y;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, x, y, "42");
	menu();
	mlx_hook(WIN, 2, 0, key_hook, env);
	mlx_do_key_autorepeaton(MLX);
	mlx_expose_hook(WIN, expose_hook, env);
	mlx_loop(MLX);
}
