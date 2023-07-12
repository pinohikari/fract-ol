/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:38:50 by hhino             #+#    #+#             */
/*   Updated: 2023/07/09 12:08:06 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_mandelbrot_color(t_complex z)
{
	int	color;

	if (z.re * z.re + z.im * z.im >= 4.0)
	{
		if (z.re * z.im >= 0)
			color = (GREEN);
		else
			color = (PURPLE);
	}
	else
		color = (BLK);
	return (color);
}

int	mandelbrot_set(double x, double y)
{
	t_complex	c;
	t_complex	z;
	int			iterations;
	double		temp;
	int			color;

	c.re = x;
	c.im = y;
	z.re = 0.0;
	z.im = 0.0;
	iterations = 0;
	while (z.re * z.re + z.im * z.im <= 4.0 && iterations < (MAX_ITERATIONS))
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = temp;
		iterations++;
	}
	color = set_mandelbrot_color(z);
	return (color);
}

void	draw_mandelbrot_set(t_data *data)
{
	int		color;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < (HEIGHT))
	{
		x = 0;
		while (x < (WIDTH))
		{
			data->cx = (x - (2 * (WIDTH) / 3)) * data->scale;
			data->cy = (y - (HEIGHT) / 2) * data->scale;
			color = mandelbrot_set(data->cx, data->cy);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}
