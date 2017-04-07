/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:59:51 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/07 16:59:00 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

int	ft_set_partern(int keycode, t_env *env)
{
	if (keycode == 18)
		env->patern = 1;
	else if (keycode == 19)
		env->patern = 2;
	else if (keycode == 20)
		env->patern = 3;
	else if (keycode == 21)
		env->patern = 4;
	else if (keycode == 53)
		exit(1);
	else if (keycode == 83)
		env->p.octaves = env->p.octaves == 1 ? 1 : env->p.octaves - 1;
	else if (keycode == 84)
		env->p.octaves++;
	else if (keycode == 86)
		env->p.gain = env->p.gain <= 0.1 ? 0.1 : env->p.gain - 0.1;
	else if (keycode == 87)
		env->p.gain += 0.1;
	else if (keycode == 89)
		env->p.height = env->p.height <= 50 ? 50 : env->p.height - 50;
	else if (keycode == 91)
		env->p.height += 50;
	ft_draw(env);
	mlx_put_image_to_window(env->mlx.ptr, env->mlx.win,
		env->mlx.img.img_ptr, 0, 0);
	return (0);
}
