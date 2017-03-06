/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:00:55 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/27 11:20:07 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>

# define MLX (env->mlx)
# define WIN (env->win)
# define MAT_X_Y(x, y) (env->matrix[x][y])
# define MAX_X (env->max_x)
# define MAX_Y (env->max_y)

# define X1 (env->xyz.x1)
# define X2 (env->xyz.x2)
# define Y1 (env->xyz.y1)
# define Y2 (env->xyz.y2)
# define Z1 (env->xyz.z1)
# define Z2 (env->xyz.z2)

# define V_DZ (env->vector.dz)
# define V_DX (env->vector.dx)
# define V_DY (env->vector.dy)
# define V_X1 (env->vector.x1)
# define V_Y1 (env->vector.y1)
# define V_X2 (env->vector.x2)
# define V_Y2 (env->vector.y2)
# define V_Z1 (env->vector.z1)
# define V_Z2 (env->vector.z2)
# define V_WXG (env->vector.wxg)
# define V_WYG (env->vector.wyg)
# define V_WZG (env->vector.wzg)

typedef	enum		e_const
{
	WIN_MAX_X = 1600,
	WIN_MAX_Y = 1200
}					t_const;

typedef struct		s_vector
{
	int			dx;
	int			dy;
	int			dz;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			z1;
	int			z2;
	int			wxg;
	int			wyg;
	int			wzg;
}					t_vector;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;

	int				max_x;
	int				max_y;

	int				**matrix;

	double			izo_x;
	double			izo_y;

	int				x;
	int				y;

	int				status;
	int				distance_x;
	int				distance_y;
	int				zoom;
	int				initial;
	double			rotating1;
	double			up_down;
	t_vector		vector;
}					t_env;

void				int_tab_del(t_env *env, int size);
void				str_tab_del(char **str, int size);
void				create_matrix(t_env *env, char **str, int max_x, int max_y);
void				print_ex(void);
void				putline(t_env *env, int x1, int y1, int x2, int y2);
void				draw(t_env *env);
int					expose_hook(t_env *env);
int					key_hook(int keycode, t_env *env);
void				window_cfg(t_env *env);
int					get_matrix_cfg(int const fd, t_env *env, int size);
void				draw_line(t_env *env);
void				menu(void);
void				get_x_y(char *str, int *x, int *y);
int					get_x(char *str);
#endif
