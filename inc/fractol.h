/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:59:40 by tfiguero          #+#    #+#             */
/*   Updated: 2023/12/06 19:48:44 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../miniLibX/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define MOUSE_DOWN		4
# define MOUSE_UP		5
# define ESC			53   // key escape
# define HEIGHT 		1080
# define WIDTH			1080
# define MLX_ERROR		0


typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	double	cx;
	double	cy;
	double	offx;
	double	offy;
	double	zoom;
}	t_fractol;

void	ft_error_params(int type, t_fractol *f);
int		ft_strcmp(char *ehe, char *cmp);
double	ft_atoi(const char	*str, double ret_int, double ret_dec, int sign);
int		ft_exit(t_fractol *f);
void	ft_check_if_nums(char *x, char *y, t_fractol *fractal);
void	ft_check_args(int argc, char **argv, t_fractol *fractal);
void	ft_mandelbrot(double x, double y);
int		ft_is_in_mandelbrot(double x, double y);
int		ft_is_in_julia(double cx, double cy, t_fractol *fractal);
void	new_window(t_fractol *f);
void	new_image(t_fractol *f);
int		get_color(int frac);
void	put_pixel(t_fractol *f, int x, int y, int color);
void	ft_error(t_fractol *f, int error);
int		read_mouse(int keycode, int x, int y, t_fractol *f);
int		read_keys(int keycode, t_fractol *f);
void	print_fractals(t_fractol *f, int frac, int x);
#endif