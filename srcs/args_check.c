/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:08:16 by tfiguero          #+#    #+#             */
/*   Updated: 2023/12/06 19:51:22 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <string.h>

void	ft_error_params(int type, t_fractol *f)
{
	if(type == 0)
		ft_putstr_fd(NO_INPUT, 2);
	else if(type == 1)
		ft_putstr_fd(NO_INPUT, 2);
	else if(type == 2)
		ft_putstr_fd(NO_INPUT, 2);
	else if(type == 3)
		ft_putstr_fd(NO_INPUT, 2);
	ft_exit(f);
}

int	ft_strcmp(char *ehe, char *cmp)
{
	int	i;

	i = 0;
	while(ehe[i] && cmp[i])
	{
		if(ehe[i] != cmp[i])
			return(1);
		i++;
	}
	if((ehe[i] && !cmp[i]) || (cmp[i] && !ehe[i]))
		return(1);
	return(0);
}

double	ft_atod(const char	*str, double ret_int, double ret_dec, int sign)
{
	int		i;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str ++;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		ret_int= (ret_int * 10) + *str - '0';
		str ++;
	}
	if(*str == '.')
	{
		str++;
		i = -1;
		while (*str && *str >= '0' && *str <= '9')
		{
			ret_dec = ret_dec + ((pow(10, i)) * (*str - '0'));
			i--;
			str++;
		}
	}
	return ((ret_int + ret_dec)* sign);
}

void	ft_check_if_nums(char *x, char *y, t_fractol *fractal)
{
	int	i;

	i = 0;
	while(x[i])
	{
		if(x[i] < '0' && x[i] > '9')
			ft_error_params(3, fractal);
		i++;
	}
	i = 0;
	while(y[i])
	{
		if(y[i] < '0' && y[i] > '9')
			ft_error_params(3, fractal);
		i++;
	}
	fractal->cx = ft_atod(x, 0, 0, 1);
	fractal->cy = ft_atod(y, 0, 0, 1);
}

void	ft_check_args(int argc, char **argv, t_fractol *fractal)
{
	int	i;

	fractal->zoom = 1;
	fractal->offx = 1;
	fractal->offy = 1;
	fractal->type = 3;
	i = -1;
	if (argc < 2)
		ft_error_params(3, fractal);
	while (argv[1][++i])
		argv[1][i] = ft_tolower(argv[1][i]);
	if(argc > 3 && (ft_strcmp(argv[1], "julia") == 0))
		fractal->type = 0;
	else if((ft_strcmp(argv[1], "mandelbrot")== 0))
		fractal->type = 1;
	else
		ft_error_params(1, fractal);
	if(fractal->type == 0 && argc > 3)
		ft_check_if_nums(argv[2], argv[3], fractal);
	else if(fractal->type == 1)
		return ;
}