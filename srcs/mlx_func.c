/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:08:23 by tfiguero          #+#    #+#             */
/*   Updated: 2023/12/06 19:11:07 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	new_window(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		ft_error(f, MLX_ERROR);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		ft_error(f, MLX_ERROR);
	new_image(f);
}

void	new_image(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		ft_error(f, MLX_ERROR);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	if (!f->addr)
		ft_error(f, MLX_ERROR);
	mlx_clear_window(f->mlx, f->win);
}

int	get_color(int frac)
{
	int	color;

	color = (frac) * (0x00FFC0CB);
	return (color);
}

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}