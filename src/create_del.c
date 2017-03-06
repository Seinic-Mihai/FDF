/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:02:01 by mseinic           #+#    #+#             */
/*   Updated: 2016/03/08 12:23:57 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	get_vals(char *str, t_env *env, int *i, int *j)
{
	int k;

	k = 0;
	while (str != NULL)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (k == 1 && *(str - 1) == '-')
				MAT_X_Y(*i, *j) = ft_atoi(str) * -1;
			else
				MAT_X_Y(*i, *j) = ft_atoi(str);
			(*i)++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
		if (*str < '0' || *str > '9')
		{
			k = 1;
			while ((*str < '0' || *str > '9') && *str != '\0')
				str++;
		}
		if (*str == '\0')
			str = NULL;
	}
}

void		create_matrix(t_env *env, char **str, int max_x, int max_y)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	max_x = 0;
	while (j < max_y && str != NULL)
	{
		i = 0;
		tmp = *str;
		get_vals(tmp, env, &i, &j);
		str++;
		j++;
	}
}

void		str_tab_del(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
}

void		int_tab_del(t_env *env, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(env->matrix[i]);
		env->matrix[i] = NULL;
		i++;
	}
	free(env->matrix);
	env->matrix = NULL;
}
