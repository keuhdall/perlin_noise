/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:05:30 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/07 17:04:02 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

void		ft_draw_patern(int x, int y, t_env *env)
{
	if (env->patern == 1)
		env->mlx.img.data[y * 800 + x] = 0xFFFFFF * ((ft_noise(x, y) + 1) / 2);
	else if (env->patern == 2)
	{
		env->mlx.img.data[y * 800 + x] =
			((((int)(((ft_noise(x, y) + 1) / 2) * 255) & 0xFF) << 16) +
			((((int)(((ft_noise(x, y) + 1) / 2) * 255) & 0xFF) << 8) +
			((((int)(((ft_noise(x, y) + 1) / 2) * 255) & 0xFF)))));
	}
	else if (env->patern == 3)
		env->mlx.img.data[y * 800 + x] = 0xFFFFFF *
				perlin_two(x, y, env);
	else if (env->patern == 4)
	{
		env->mlx.img.data[y * 800 + x] =
			((((int)(((perlin_two(x, y, env) + 1) / 2) * 255) & 0xFF) << 16) +
			((((int)(((perlin_two(x, y, env) + 1) / 2) * 255) & 0xFF) << 8) +
			((((int)(((perlin_two(x, y, env) + 1) / 2) * 255) & 0xFF)))));
	}
}

void		ft_draw(t_env *env)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
			ft_draw_patern(x, y, env);
	}
}
