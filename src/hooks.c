/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:04:07 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/16 15:09:35 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			expose_hook(t_env *env)
{
	draw(env);
	return (0);
}

static void	rotating_zooming(int keycode, t_env *env)
{
	if (keycode == 69)
		env->zoom += 1;
	if (keycode == 78 && env->zoom > 1)
		env->zoom -= 1;
	if (keycode == 116 && env->initial != 0)
		env->up_down += 0.5;
	if (keycode == 121 && env->initial != 0)
		env->up_down -= 0.5;
	if (keycode == 86)
		env->rotating1 += 0.5;
	if (keycode == 88)
		env->rotating1 -= 0.5;
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 18)
	{
		env->initial = 0;
		env->up_down = 0;
		env->rotating1 = 0;
	}
	if (keycode == 19)
	{
		env->initial = 1;
		env->up_down = 0.5;
		env->rotating1 = 0.5;
	}
	if (keycode == 126)
		env->distance_y -= 10;
	if (keycode == 125)
		env->distance_y += 10;
	if (keycode == 123)
		env->distance_x -= 10;
	if (keycode == 124)
		env->distance_x += 10;
	rotating_zooming(keycode, env);
	expose_hook(env);
	return (0);
}
