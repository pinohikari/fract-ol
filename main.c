/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:02:36 by hhino             #+#    #+#             */
/*   Updated: 2023/07/09 14:09:34 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	judge_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Error: enter \"mandelbrot\" or \"julia\".\n");
		exit(0);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
			"julia") != 0)
	{
		ft_putstr("Error: enter \"mandelbrot\" or \"julia\".\n");
		exit(0);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc != 2)
	{
		ft_putstr("Error: too much arguments.\nEnter only \"mandelbrot\".\n");
		exit(0);
	}
	else if (ft_strcmp(argv[1], "julia") == 0 && argc != 4)
	{
		ft_putstr("Error: enter TWO numbers.\n");
		exit(0);
	}
}

void	put_num_to_julia(char **argv, t_data *data)
{
	double	argv2;
	double	argv3;

	argv2 = ft_atof(argv[2]);
	argv3 = ft_atof(argv[3]);
	if ((-2 <= argv2 && argv2 <= 2) && (-2 <= argv3 && argv3 <= 2))
	{
		data->flag = 2;
		data->c_re = argv2;
		data->c_im = argv3;
		draw_julia_set(data);
	}
	else
	{
		ft_putstr("Error: enter two numbers between -2 and +2.\n");
		exit(0);
	}
}

void	judge_set(char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		draw_mandelbrot_set(data);
		data->flag = 1;
	}
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (isdouble(argv[2]) == 1 && isdouble(argv[3]) == 1)
			put_num_to_julia(argv, data);
		else
		{
			ft_putstr("Error: enter two numbers between -2 and +2.\n");
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.scale = 0.003;
	judge_args(argc, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (WIDTH), (HEIGHT), "Fract-ol");
	data.img = mlx_new_image(data.mlx, (WIDTH), (HEIGHT));
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	judge_set(argv, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 1L << 2, close_window_botton, &data);
	mlx_hook(data.win, 2, 1L << 0, close_window_esc, &data);
	mlx_loop(data.mlx);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fract-ol");
// }

// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);
// }
