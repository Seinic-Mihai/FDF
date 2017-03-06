/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 11:01:38 by mseinic           #+#    #+#             */
/*   Updated: 2016/03/08 11:14:02 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		matrix(t_env *env, char **str)
{
	int i;

	i = 0;
	if ((env->matrix = (int **)malloc(sizeof(int *) * MAX_X)) != NULL)
	{
		while (i < MAX_X)
		{
			if ((env->matrix[i] = (int *)malloc(sizeof(int) * MAX_Y)) == NULL)
				return (0);
			i++;
		}
		create_matrix(env, str, MAX_X, MAX_Y);
	}
	return (1);
}

static int		error_ret(char **str, int size)
{
	if (str != NULL)
		str_tab_del(str, size);
	ft_putstr("Wrong line cfg.\n");
	print_ex();
	return (0);
}

int				get_matrix_cfg(int const fd, t_env *env, int size)
{
	char	**str;
	char	*tmp;

	str = (char **)malloc(sizeof(char *) * (size + 1));
	while ((get_next_line(fd, &(*str))) > 0)
	{
		tmp = *str;
		get_x_y(tmp, &MAX_X, &MAX_Y);
		str++;
	}
	str = str - MAX_Y;
	if (MAX_Y != 0 && MAX_X % MAX_Y == 0)
		MAX_X /= MAX_Y;
	else
		return (error_ret(str, size));
	if (matrix(env, str) == 0)
	{
		str_tab_del(str, size);
		return (0);
	}
	if (str != NULL)
		str_tab_del(str, size);
	return (1);
}
