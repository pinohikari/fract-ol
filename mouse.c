/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:38:11 by hhino             #+#    #+#             */
/*   Updated: 2023/07/08 15:01:25 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data)
{
	data->scale *= 0.9;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, (WIDTH), (HEIGHT));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->flag == 1)
		draw_mandelbrot_set(data);
	else if (data->flag == 2)
		draw_julia_set(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_out(t_data *data)
{
	data->scale *= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, (WIDTH), (HEIGHT));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->flag == 1)
		draw_mandelbrot_set(data);
	else if (data->flag == 2)
		draw_julia_set(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		zoom_in(data);
	if (mousecode == 5)
		zoom_out(data);
	return (0);
}
