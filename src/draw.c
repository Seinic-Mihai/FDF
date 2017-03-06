/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:16:04 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/16 16:29:16 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	calculating(t_env *env, int x, int y, int z)
{
	double r1;

	r1 = env->rotating1;
	env->izo_x = (double)x * cos(r1) - sin(r1) * (double)y;
	env->izo_y = (double)(-z * env->up_down) + sin(r1) * (double)x
							+ cos(r1) * (double)y;
}

static void	zooming(t_env *env, int status)
{
	if (status == 1)
	{
		V_X1 = env->izo_x * env->zoom;
		V_Y1 = env->izo_y * env->zoom;
	}
	else if (status == 2)
	{
		V_X2 = env->izo_x * env->zoom;
		V_Y2 = env->izo_y * env->zoom;
	}
}

static void	proj(t_env *env, int x, int y)
{
	V_Z1 = MAT_X_Y(x, y);
	if (x + 1 < MAX_X)
	{
		calculating(env, x, y, V_Z1);
		zooming(env, 1);
		V_Z2 = MAT_X_Y(x + 1, y);
		calculating(env, x + 1, y, V_Z2);
		zooming(env, 2);
		draw_line(env);
	}
	if (y + 1 < MAX_Y)
	{
		calculating(env, x, y, V_Z1);
		zooming(env, 1);
		V_Z2 = MAT_X_Y(x, y + 1);
		calculating(env, x, y + 1, V_Z2);
		zooming(env, 2);
		draw_line(env);
	}
}

void		draw(t_env *env)
{
	int		local;

	env->x = 0;
	mlx_clear_window(MLX, WIN);
	while (MAX_X * env->zoom + env->distance_x < WIN_MAX_X - 600 && MAX_Y *
			env->zoom + env->distance_y < WIN_MAX_Y - 600 && env->status == 0)
	{
		env->zoom += 1;
		local = 1;
	}
	if (local)
		env->status = 1;
	while (env->x < MAX_X)
	{
		env->y = 0;
		while (env->y < MAX_Y)
		{
			proj(env, env->x, env->y);
			env->y++;
		}
		env->x++;
	}
}
