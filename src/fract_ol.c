/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:03:42 by tfiguero          #+#    #+#             */
/*   Updated: 2023/12/06 19:47:58 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_error(t_fractol *f, int error)
{
	if (error == MLX_ERROR)
		write(2, "Mlx error :(\n", 19);
	ft_exit(f);
}
int	ft_exit(t_fractol *f)
{
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	exit(0);
}

void	print_fractals(t_fractol *f, int frac, int x)
{
	int	y;

	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			if (f->type == 1)
				frac = ft_is_in_mandelbrot(-2.5 * f->zoom
						+ (double)x * f->zoom * 5 / WIDTH, 2.5
						* f->zoom + (double)y * f->zoom * -5 / HEIGHT);
			if (f->type == 0)
				frac = ft_is_in_julia(-2.5 * f->zoom + (double)x * f->zoom
						* 5 / WIDTH, 2.5 * f->zoom + (double)y
						* f->zoom * -5 / HEIGHT, f);
			if (frac == 0)
				put_pixel(f, x, y, 0x000000);
			else if (frac > 0)
				put_pixel(f, x, y, get_color(frac));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_fractol	f;

	ft_check_args(argc, argv, &f);
	new_window(&f);
	print_fractals(&f, 0, 0);
	mlx_key_hook(f.win, read_keys, &f);
	mlx_mouse_hook(f.win, read_mouse, &f);
	mlx_hook(f.win, 17, 0, ft_exit, &f);
	mlx_loop(f.mlx);
	return (0);
}