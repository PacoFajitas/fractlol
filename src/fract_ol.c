/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:03:42 by tfiguero          #+#    #+#             */
/*   Updated: 2023/11/01 23:52:44 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/fractol.h"
 # include "../miniLibX/mlx.h"
 

 void	ft_check_args(int argc, char **argv, t_fractol fractal)
 {

 }
int     ft_exit(t_ventana *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

int     read_keys(int key_pressed, void *param)
{
        t_img *img;

        img = (t_img *)param;
        if (key_pressed == ESC || !img)
                ft_exit(&img->win);
        else
                return (-1);
        mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
        return (0);
}


void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

t_ventana new_program(char *str)
{
	t_ventana ret;

	ret.mlx_ptr = mlx_init();
	ret.height = HEIGHT;
	ret.width = WIDTH;
	ret.win_ptr = mlx_new_window(ret.mlx_ptr, ret.width, ret.height, str);
	return (ret);
}

t_img	new_img(int w, int h, t_ventana window)
{
	t_img	image;

 	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}
// int	ft_mouse_handler(int param, t_img *png)
// {
// 	printf("%");
// 	return(1);
// }
int	main(int argc, char **argv)
{
	t_fractol fractal;
	double	y;
	double	x;
	int		max_im;
	double	re;
	double	im;
	int		i;

	ft_check_args(argc, argv, fractal);
	fractal.imagen.win = new_program("Fractlol");
	if (!fractal.imagen.win.mlx_ptr || !fractal.imagen.win.win_ptr)
		return (1);
	fractal.imagen = new_img(WIDTH, HEIGHT, fractal.imagen.win);

	x = 0;
	mlx_clear_window(fractal.imagen.win.mlx_ptr, fractal.imagen.win.win_ptr);
	max_im = -2.0 + (2.0 - (-2.0)) * WIDTH / HEIGHT;
	while (x < fractal.imagen.h)
	{
		y = 0;
		while (y < fractal.imagen.w)
		{
			re = -2.0 + (double)x * (2.0 - (-2.0)) / WIDTH;
			im = max_im + (double)y * (-2.0 - 2.0) / HEIGHT;
			i = ft_is_in_mandelbrot(re, im);
			if(i)
				put_pixel_img(fractal.imagen, x, y, (0x00ACCB) * i/2);
			// ft_mandelbrot(re,im);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window (fractal.imagen.win.mlx_ptr, fractal.imagen.win.win_ptr, fractal.imagen.img_ptr, 0, 0);
	mlx_key_hook (fractal.imagen.win.win_ptr, read_keys, &fractal.imagen);
	//mlx_key (a.win_ptr, 2, 0, read_keys, &png);
	// mlx_hook (a.win_ptr, 4, 0, ft_mouse_handler , &png);
	// mlx_hook (a.win_ptr, 6, 0, mouse_handler , &png);
	mlx_hook (fractal.imagen.win.win_ptr, 17, 0, ft_exit , &fractal.imagen);
	mlx_loop(fractal.imagen.win.mlx_ptr);
	
	exit (0);
}
// int	main()
// {
// 	ft_mandelbrot(-0.16, -1.04);
// }