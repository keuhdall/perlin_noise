/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:13:25 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/05 22:09:39 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

double	ft_rand_noise(int t)
{
	t = (t << 13) ^ t;
	t = (t * (t * t * 15731 + 789221) + 1376312589);
	return (1.0 - (t & 0x7fffffff) / 1073741824.0);
}

double	ft_noise(int x, int y)
{
	int	tmp;

	tmp = ft_rand_noise(x) * 850000;
	return (ft_rand_noise(tmp + y));
}

void	ft_init_struct(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 800, 600, "perlin");
	mlx->img.img_ptr = mlx_new_image(mlx->ptr, 800, 600);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
		&mlx->img.size_line, &mlx->img.endian);
}

int		main(void)
{
	int		x;
	int		y;
	t_mlx	mlx;

	ft_init_struct(&mlx);
	x = -1;
	while (++x < 800)
	{
		y = -1;
		while (++y < 600)
			mlx.img.data[y * 800 + x] = 0xFFFFFF * ((ft_noise(x, y) + 1) / 2);
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
