/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:03:10 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/16 16:35:35 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		distance(t_env *env)
{
	V_X1 += env->distance_x;
	V_Y1 += env->distance_y;
	V_X2 += env->distance_x;
	V_Y2 += env->distance_y;
	V_DX = abs(V_X1 - V_X2);
	V_DY = abs(V_Y1 - V_Y2);
	V_DZ = abs((int)(V_Z1 * env->up_down) - (int)(V_Z2 * env->up_down));
	V_WXG = (V_X1 > V_X2 ? -1 : 1);
	V_WYG = (V_Y1 > V_Y2 ? -1 : 1);
	V_WZG = ((int)(V_Z1 * env->up_down) > (int)(V_Z2 * env->up_down) ? -1 : 1);
}

static size_t	get_color(int z)
{
	int limit;

	limit = 15;
	if (z < 0)
		return (((z * 255) / limit) + 0x000000FF);
	else if (z < limit)
		return (0x00FFE010 - (((z * 255) / limit) << 16));
	else
		return (0x00FFFFFF);
}

void			draw_line(t_env *env)
{
	int i;

	distance(env);
	i = 0;
	if (V_DX > V_DY)
		while (i <= V_DX)
		{
			if (V_DX != 0)
				mlx_pixel_put(MLX, WIN, V_X1 + i * V_WXG,
							V_Y1 + ((i * V_DY) / V_DX) * V_WYG,
							get_color((int)(V_Z1 * env->up_down) +
							V_WZG * ((i * V_DZ) / V_DX)));
			i++;
		}
	else
		while (i <= V_DY)
		{
			if (V_DY != 0)
				mlx_pixel_put(MLX, WIN, V_X1 + ((i * V_DX) / V_DY) * V_WXG,
							V_Y1 + i * V_WYG,
							get_color((int)(V_Z1 * env->up_down) +
							V_WZG * ((i * V_DZ) / V_DY)));
			i++;
		}
}
