/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:16:30 by hhino             #+#    #+#             */
/*   Updated: 2023/07/09 11:52:31 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	decimal_point(const char *str, size_t i, double ans)
{
	double	j;

	j = 0.1;
	while (ft_isdigit(str[i]))
	{
		ans += j * (str[i] - '0');
		j *= 0.1;
		i++;
	}
	return (ans);
}

double	ft_atof(const char *str)
{
	size_t	i;
	double	ans;
	int		sign_flag;

	i = 0;
	ans = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign_flag = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		ans = decimal_point(str, i, ans);
	}
	if (sign_flag == -1)
		ans = -ans;
	return (ans);
}
