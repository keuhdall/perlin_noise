/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:05:30 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/05 23:13:22 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"


void	ft_draw_patern(t_mlx *mlx, int x, int y)
{
	if (mlx->patern == 1)
			mlx->img.data[y * 800 + x] = 0xFFFFFF * ((ft_noise(x, y) + 1) / 2);
	else if (mlx->patern == 2)
	{
			mlx->img.data[y * 800 + x] =
				((((int)(((ft_noise(x, y) + 1) / 2) * 255) & 0xFF) << 16) +
				((((int)(((ft_noise(x, y) + 1) / 2) * 255) & 0xFF) << 8) +
				((((int)(((ft_noise(x, y) + 1) / 2) * 255) & 0xFF)))));
	}
}

void	ft_draw(t_mlx *mlx)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
			ft_draw_patern(mlx, x, y);
	}
}
