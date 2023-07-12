/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:28 by hhino             #+#    #+#             */
/*   Updated: 2023/07/09 14:08:55 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*buff_s1;
	const unsigned char	*buff_s2;

	buff_s1 = (const unsigned char *)s1;
	buff_s2 = (const unsigned char *)s2;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return ((int)(buff_s1[i] - buff_s2[i]));
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*str++ != '\0')
		n++;
	return (n);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isdouble(char *str)
{
	int	i;
	int	dotcount;
	int	signcount;

	i = 0;
	dotcount = 0;
	signcount = 0;
	if (ft_strlen(str) > 10)
		return (0);
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-'
				|| str[i] == '+'))
			return (0);
		if (str[i] == '.')
			dotcount++;
		if (str[i] == '+' || str[i] == '-')
			signcount++;
		i++;
	}
	if (dotcount > 1 || signcount > 1 || (ft_strlen(str) == 1 && dotcount == 1)
		|| (ft_strlen(str) == 1 && signcount == 1))
		return (0);
	return (1);
}
