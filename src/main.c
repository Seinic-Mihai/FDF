/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:42:54 by mseinic           #+#    #+#             */
/*   Updated: 2016/03/08 11:27:25 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	verif(char *str)
{
	int i;

	i = 1;
	while (*str != '\0' && i == 1)
	{
		if ((*str < '0' || *str > '9') &&
			(*str != ' ' && *str != '\t' && *str != '-'))
			i = 0;
		str++;
	}
	return (i);
}

static int	get_the_size(int const fd, int *size)
{
	char	*str;
	int		i;
	int		first;
	int		other;

	first = 0;
	other = 0;
	str = NULL;
	i = 0;
	while ((get_next_line(fd, &str)) > 0)
	{
		if (first == 0)
		{
			first = get_x(str);
			other = first;
		}
		else
			other = get_x(str);
		i = verif(str);
		(*size)++;
		ft_strdel(&str);
		if (i == 0 || (first != other || first == 0))
			return (0);
	}
	return (i);
}

static void	init(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->distance_x = 400;
	env->distance_y = 200;
	env->zoom = 2;
	env->up_down = 0.5;
	env->rotating1 = 0.5;
	env->initial = 1;
}

static void	message(void)
{
	ft_putstr("Wrong filename or file config!\033[1;91m");
	ft_putstr(" Be careful what you give as a parametre.\n\033[0m");
	print_ex();
}

int			main(int ac, char **av)
{
	t_env	env;
	int		fd;
	int		size;

	init(&env);
	size = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) >= 0 && get_the_size(fd, &size))
		{
			close(fd);
			fd = open(av[1], O_RDONLY);
			if (get_matrix_cfg(fd, &env, size))
				window_cfg(&env);
			if (env.matrix != NULL)
				int_tab_del(&env, env.max_x);
		}
		else
			message();
		close(fd);
	}
	else
		ft_putstr("\033[1;91mSory for now i can work only with 1 map\n\033[0m");
	return (0);
}
