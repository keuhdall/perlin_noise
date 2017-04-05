/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:28:58 by lmarques          #+#    #+#             */
/*   Updated: 2017/04/05 23:16:54 by lmarques         ###   ########.fr       */
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
