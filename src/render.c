/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:12:48 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/19 22:49:48 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
//Mandelbrot: El valor fijo es z y el variable es c en z = (z*z) + c;
//Julia: El valor fijo es c y el variable es z en z = (z*z) + c;
//Ambas funciones son iterativas, por lo que se iteran un numero maximo de veces
//para definir si el numero que estamos estudiando forma parte de cualquiera de los dos sets
//sustituyendo la z por el resultado de la iteracion anterior


int	ft_is_in_mandelbrot(double x, double y)
{
	double	i;
	int		k;

	k = 0;
	while(k < 50)
	{
		i = (x * x) - (y * y);//.0625
		y = 2 * x * y;//.5
		x = i;
		// printf("En la iteracion : %i x es %f y y es %fla raiz cuadrada de x^2 + y^2 es: %.30f\n", k , x, y, sqrtf((x * x) + (y * y)));//.25
		if((x * x) + (y * y) > 4)
			return(1);
		k++;
	}
	return(0);

}

void	ft_mandelbrot(double x, double y)
{
 	int	i;
	int	z;
	double max_im;
	double im;
	i = 0;
	max_im = 0;
	z = 0;

	im = ft_is_in_mandelbrot(x, y);
	printf("%.8f", im);
}