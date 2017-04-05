/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:13:34 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/05 23:16:39 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# include <math.h>
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
	int			patern;
}				t_mlx;

int				ft_exit(void);
double			ft_noise(int x, int y);
void			ft_draw(t_mlx *mlx);
int				ft_set_partern(int keycode, t_mlx *mlx);

#endif
