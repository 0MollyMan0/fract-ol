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

int	get_color(double iter)
{
	double t;
	int	r;
	int	g;
	int	b;

	if (iter == 100)
		return (0);
	t = iter / 100.0;
	r = t * 255;
	g = 0;
	b = 255;
	return (r << 16 | g << 8 | b);
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
			put_pixel(&data->img, x, y, get_color(mandelbrot(c_re, c_im)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

