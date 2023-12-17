/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:45:40 by tfiguero          #+#    #+#             */
/*   Updated: 2023/12/06 19:48:24 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	read_keys(int keycode, t_fractol *f)
{
	if (keycode == ESC)
		ft_exit(f);
	mlx_clear_window(f->mlx, f->win);
	print_fractals(f, 0, 0);
	return (0);
}

int	read_mouse(int keycode, int x, int y, t_fractol *f)
{
	x = 0;
	y = 0;
	if (keycode == MOUSE_DOWN)
		f->zoom *= 1.2;
	if (keycode == MOUSE_UP)
		f->zoom *= 0.8;
	mlx_clear_window(f->mlx, f->win);
	print_fractals(f, 0, 0);
	return (0);
}