/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:13:34 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/07 17:08:39 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define PERSISTANCE 0.01
# define OCTAVES 1
# define PAS 1

# include <math.h>
# include <time.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_perlin
{
	float		gain;
	int			octaves;
	int			height;
}				t_perlin;

typedef struct	s_env
{
	t_mlx		mlx;
	t_perlin	p;
	int			patern;
}				t_env;

int				ft_exit(void);
double			ft_noise(int x, int y);
float			ft_perlin(float x, float y, t_env *env);
void			ft_draw(t_env *env);
int				ft_set_partern(int keycode, t_env *env);

#endif
