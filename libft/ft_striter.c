/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 01:30:50 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:41:16 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int	count;

	count = 0;
	if (!s || !f)
		return ;
	while (s[count])
	{
		(*f)(&s[count]);
		count++;
	}
}
