/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:56:51 by hhino             #+#    #+#             */
/*   Updated: 2023/07/14 17:59:49 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// c.re =  -0.8;
// c.im = 0.156;
// c.re = 0.32;
// c.im = 0.043;

int	set_julia_color(t_complex z)
{
	int	color;

	if (z.re * z.re + z.im * z.im >= 4.0)
	{
		if (z.re + z.im < 0)
			color = (AQUA);
		else
			color = (TEAL);
	}
	else
		color = (BLK);
	return (color);
}

int	julia_set(double x, double y, t_data data)
{
	t_complex	c;
	t_complex	z;
	int			iterations;
	double		temp;
	int			color;

	z.re = x;
	z.im = y;
	c.re = data.c_re;
	c.im = data.c_im;
	iterations = 0;
	while (z.re * z.re + z.im * z.im < 4.0 && iterations < MAX_ITERATIONS)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = temp;
		iterations++;
	}
	color = set_julia_color(z);
	return (color);
}

void	draw_julia_set(t_data *data)
{
	int	color;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (HEIGHT))
	{
		x = 0;
		while (x < (WIDTH))
		{
			data->cx = (x - (WIDTH) / 2) * data->scale;
			data->cy = (y - (HEIGHT) / 2) * data->scale;
			color = julia_set(data->cx, data->cy, *data);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}
