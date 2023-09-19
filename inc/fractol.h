/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:59:40 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/19 22:26:16 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ESC 53   // key escape
# define ENTER 36 // key "enter"
# define FOLLOW 3 // key "f"
# define COLOR 8  // key "c"
# define UP 126   // key "arrow up"
# define DOWN 125 // key "arrow down"
# define PENGUIN 35 // key "p"
# define RAND_COLOR 15 // key "r"

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


void	ft_mandelbrot(double x, double y);
int		ft_is_in_mandelbrot(double x, double y);
#endif