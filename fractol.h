/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:26:51 by hhino             #+#    #+#             */
/*   Updated: 2023/07/12 14:27:36 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <complex.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITERATIONS 100

# define PURPLE 0x007B68EE
# define GREEN 0x007FFFD4
# define BLK 0x00000000
# define AQUA 0x00007FFD4
# define TEAL 0x00008B8B

typedef struct s_data
{
	double	cx;
	double	cy;

	double	scale;

	double	c_re;
	double	c_im;

	int		flag;

	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

// utils.c
void		ft_putstr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
int			ft_isdigit(int c);
int			isdouble(char *str);

// utils2.c
double		ft_atof(const char *str);

// close.c
int			close_window_botton(t_data *data);
int			close_window_esc(int keycode, t_data *data);

// mouse.c
void		zoom_in(t_data *data);
void		zoom_out(t_data *data);
int			mouse_hook(int mousecode, int x, int y, t_data *data);

//julia.c
int			set_julia_color(t_complex z);
// julia_ver2.c
int			set_julia_gradation(int iterations, int color);
int			julia_set(double x, double y, t_data data);
void		draw_julia_set(t_data *data);

//mandelbrot.c
int			set_mandelbrot_color(t_complex z);
// mandelbrot_ver2.c
int			set_mandelbrot_gradation(int iterations, int color);
int			mandelbrot_set(double x, double y);
void		draw_mandelbrot_set(t_data *data);

// main.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		judge_args(int argc, char **argv);
void		put_num_to_julia(char **argv, t_data *data);
void		judge_set(char **argv, t_data *data);
int			main(int argc, char **argv);

#endif
