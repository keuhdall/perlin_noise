/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:13:25 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/05 23:19:06 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

void	ft_init_struct(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 800, 600, "perlin");
	mlx->img.img_ptr = mlx_new_image(mlx->ptr, 800, 600);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
		&mlx->img.size_line, &mlx->img.endian);
	mlx->patern = 1;
}

int		main(void)
{
	t_mlx	mlx;

	ft_init_struct(&mlx);
	ft_draw(&mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win, &ft_set_partern, &mlx);
	mlx_hook(mlx.win, 17, (1L << 17), &ft_exit, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
