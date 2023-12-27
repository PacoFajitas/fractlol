/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:12:48 by tfiguero          #+#    #+#             */
/*   Updated: 2023/12/06 19:49:35 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
//Mandelbrot: El valor fijo es z y el variable es c en z = (z*z) + c; 
//Julia: El valor fijo es c y el variable es z en z = (z*z) + c;
//Ambas funciones son iterativas, por lo que se iteran un numero maximo de veces
//para definir si el numero que estamos estudiando forma parte de cualquiera de los dos sets
//sustituyendo la z por el resultado de la iteracion anterior


int	ft_is_in_julia(double cx, double cy, t_fractol *fractal)
{
	double	i;
	int		k;
	double	x;
	double	y;
	
	k = 0;
	x = fractal->cx;
	y = fractal->cy;
	while(k < 40)
	{
		i = pow(cx,2) - pow(cy, 2) + x;//.0625
		cy = 2 * cx * cy + y;//.5
		cx = i;
		if(pow(cx,2) + pow(cy,2) > 4)
			return(k);
		k++;
	}
	return(0);

}
int	ft_is_in_mandelbrot(double cx, double cy)
{
	double	i;
	int		k;
	double	x;
	double	y;
	
	k = 0;
	x = 0;
	y = 0;
	while(k < 40)
	{
		i = pow(x,2) - pow(y, 2) + cx;//.0625
		y = 2 * x * y + cy;//.5
		x = i;
		k++;
		if(pow(x,2) + pow(y,2) > 4)
			return(k);
	}
	return(0);

}
