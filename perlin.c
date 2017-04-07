/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:13:25 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/07 17:12:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

void	ft_init_perlin(t_env *env)
{
	env->p.gain = 0.75;
	env->p.octaves = 8;
	env->p.height = WIN_HEIGHT;
}

void	ft_init_struct(t_env *env)
{
	env->mlx.ptr = mlx_init();
	env->mlx.win = mlx_new_window(env->mlx.ptr, 800, 600, "perlin");
	env->mlx.img.img_ptr = mlx_new_image(env->mlx.ptr, 800, 600);
	env->mlx.img.data = (int *)mlx_get_data_addr(env->mlx.img.img_ptr,
		&env->mlx.img.bpp, &env->mlx.img.size_line, &env->mlx.img.endian);
	env->patern = 1;
}

int		main(void)
{
	t_env		env;

	ft_init_struct(&env);
	ft_init_perlin(&env);
	ft_draw(&env);
	mlx_put_image_to_window(env.mlx.ptr, env.mlx.win,
		env.mlx.img.img_ptr, 0, 0);
	mlx_key_hook(env.mlx.win, &ft_set_partern, &env);
	mlx_hook(env.mlx.win, 17, (1L << 17), &ft_exit, 0);
	mlx_loop(env.mlx.ptr);
	return (0);
}
