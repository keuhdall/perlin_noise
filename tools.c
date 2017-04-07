/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:28:58 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/07 17:03:19 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"

int	ft_exit(void)
{
	exit(1);
	return (0);
}

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

float	interpolate(float a, float b, float x)
{
	float	pi_mod;
	float	f_unk;

	pi_mod = x * 3.1415927;
	f_unk = (1 - cos(pi_mod)) * 0.5;
	return (a * (1 - f_unk) + b * x);
}

float	smooth_noise(int x, int y)
{
	float	corners;
	float	center;
	float	sides;

	corners = (ft_noise(x - 1, y - 1) + ft_noise(x + 1, y - 1) +
			ft_noise(x - 1, x + 1) + ft_noise(x + 1, y + 1)) / 16;
	sides = (ft_noise(x - 1, y) + ft_noise(x + 1, y) + ft_noise(x, y - 1) +
			ft_noise(x, y + 1)) / 8;
	center = ft_noise(x, y) / 4;
	return (corners + sides + center);
}

float	noise_handler(float x, float y)
{
	int		int_val[2];
	float	frac_val[2];
	float	value[4];
	float	res[2];

	int_val[0] = (int)x;
	int_val[1] = (int)y;
	frac_val[0] = x - int_val[0];
	frac_val[1] = y - int_val[1];
	value[0] = smooth_noise(int_val[0], int_val[1]);
	value[1] = smooth_noise(int_val[0] + 1, int_val[1]);
	value[2] = smooth_noise(int_val[0], int_val[1] + 1);
	value[3] = smooth_noise(int_val[0] + 1, int_val[1] + 1);
	res[0] = interpolate(value[0], value[1], frac_val[0]);
	res[1] = interpolate(value[2], value[3], frac_val[0]);
	return (interpolate(res[0], res[1], frac_val[1]));
}

float	ft_perlin(float x, float y, t_env *env)
{
	int i;
	float total = 0.0f;
	float frequency = 1.0f/(float)env->p.height;
	float amplitude = env->p.gain;
	float lacunarity = 2.0;

	for (i = 0; i < env->p.octaves; ++i)
	{
		total += noise_handler((float)x * frequency, (float)y * frequency) * amplitude;
		frequency *= lacunarity;
		amplitude *= env->p.gain;
	} 
	return (total);
}
