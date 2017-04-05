/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:59:51 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/05 23:22:17 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

int	ft_set_partern(int keycode, t_mlx *mlx)
{
	if (keycode == 18)
		mlx->patern = 1;
	else if (keycode == 19)
		mlx->patern = 2;
	else if (keycode == 53)
		exit(1);
	ft_draw(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}
