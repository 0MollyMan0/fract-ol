/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:21:17 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/17 14:21:30 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

static int	get_color(double iter, t_data *data)
{
	double t;

	if (iter == 100)
		return (0);
	t = iter / 100.0;
	if (data->palette == 0)
		return palette_rgb(t);
	else if (data->palette == 1)
		return palette_fire(iter);
	else if (data->palette == 2)
		return palette_blue_white(iter);
	else if (data->palette == 3)
		return red_to_yellow(t);
	else if (data->palette == 4)
		return yellow_to_green(t);
	else if (data->palette == 5)
		return green_to_cyan(t);
	else if (data->palette == 6)
		return cyan_to_blue(t);
	else if (data->palette == 7)
		return blue_to_violet(t);
	return violet_to_red(t);
}

void	render(t_data *data)
{
	int	x;
	int	y;
	const int wh = 1080;
	double	c_re;
	double	c_im;

	x = 0;
	while (x < wh)
	{
		y = 0;
		while (y < wh)
		{
			c_re = (x - wh / 2.0) / (0.5 * data->zoom * wh) + data->offset_x;
			c_im = (y - wh / 2.0) / (0.5 * data->zoom * wh) + data->offset_y;
			put_pixel(&data->img, x, y, get_color(mandelbrot(c_re, c_im), data));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

