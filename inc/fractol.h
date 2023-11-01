/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:59:40 by tfiguero          #+#    #+#             */
/*   Updated: 2023/10/05 23:32:16 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ESC	53   // key escape
# define HEIGHT 1000
# define WIDTH	1000

typedef struct  s_ventana
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_ventana;

typedef struct s_img
{
	t_ventana	win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef	struct s_fractol
{
	t_img	imagen;
	double	cx;
	double	cy;
}				t_fractol;



void	ft_mandelbrot(double x, double y);
int		ft_is_in_mandelbrot(double x, double y);
int		ft_is_in_julia(double cx, double cy);
#endif