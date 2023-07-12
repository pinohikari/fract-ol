/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_ver2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:15:05 by hhino             #+#    #+#             */
/*   Updated: 2023/07/10 10:03:34 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_mandelbrot_gradation(int iterations, int color)
{
	if (iterations > 100)
		color = 0x00e0FFFF;
	else if (iterations > 90)
		color = 0x00AFEEEE;
	else if (iterations > 70)
		color = 0x00ADD8E6;
	else if (iterations > 50)
		color = 0x0087CEEB;
	else if (iterations > 30)
		color = 0x0087CEFA;
	else if (iterations > 10)
		color = 0x0000BFFF;
	else if (iterations > 5)
		color = 0x000000FF;
	else if (iterations > 3)
		color = 0x000000CD;
	else if (iterations > 2)
		color = 0x00191970;
	else if (iterations > 1)
		color = 0x00191970;
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
	color = 0;
	while (z.re * z.re + z.im * z.im <= 4.0 && iterations < (MAX_ITERATIONS))
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = temp;
		iterations++;
	}
	if (z.re * z.re + z.im * z.im > 4.0)
		color = set_mandelbrot_gradation(iterations, color);
	else
		color = (BLK);
	return (color);
}

void	draw_mandelbrot_set(t_data *data)
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
			data->cx = (x - (2 * (WIDTH) / 3)) * data->scale;
			data->cy = (y - (HEIGHT) / 2) * data->scale;
			color = mandelbrot_set(data->cx, data->cy);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}
