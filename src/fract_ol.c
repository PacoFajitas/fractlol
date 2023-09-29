/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:03:42 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/29 11:20:18 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/fractol.h"
 # include "../miniLibX/mlx.h"

int     exit_tutorial(t_ventana *window);

int get_color()
{
        return (rand() % 2147483647);
}

int     read_keys(int key_pressed, void *param)
{
        t_img *img;

        img = (t_img *)param;
        if (key_pressed == ESC || !img)
                exit_tutorial(&img->win);
        // else if (key_pressed == FOLLOW)
        //         follow = !follow;
        // else if (key_pressed == COLOR)
        //         color = get_color();
        //else if (key_pressed == PENGUIN)
        //        penguin(*img);
        else
                return (-1);
        mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
        return (0);
}
int     exit_tutorial(t_ventana *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

t_ventana new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_ventana) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
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
int	ft_exit(void)
{
	exit(0);
}
int	main()
{
	t_ventana a;
	t_img png;
	double	y;
	double	x;
	int		max_im;
	double	re;
	double	im;
	int		i;
	
	a = new_program(1000, 1000, "Fractlol");
	if (!a.mlx_ptr || !a.win_ptr)
		return (1);
	png = new_img(1000, 1000, a);

	x = 0;
	mlx_clear_window(a.mlx_ptr, a.win_ptr);
	max_im = -2.0 + (2.0 - (-2.0)) * 1000 / 1000;
	while (x < png.h)
	{
		y = 0;
		while (y < png.w)
		{
			re = -2.0 + (double)x * (2.0 - (-2.0)) / 1000;
			im = max_im + (double)y * (-2.0 - 2.0) / 1000;
			i = ft_is_in_julia(re, im);
			if(i)
				put_pixel_img(png, x, y, (0xFCBE11) * i);
			// ft_mandelbrot(re,im);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window (png.win.mlx_ptr, png.win.win_ptr, png.img_ptr, 0, 0);
	mlx_key_hook (a.win_ptr, read_keys, &png);
	//mlx_key (a.win_ptr, 2, 0, read_keys, &png);
	mlx_hook (a.win_ptr, 5, 0, mouse_handler , &png);
	mlx_hook (a.win_ptr, 6, 0, mouse_handler , &png);
	mlx_hook (a.win_ptr, 17, 0, ft_exit , &png);
	mlx_loop(a.mlx_ptr);
	
	exit (0);
}
// int	main()
// {
// 	ft_mandelbrot(-0.16, -1.04);
// }