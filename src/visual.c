/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:21:17 by anfouger          #+#    #+#             */
/*   Updated: 2026/01/02 14:08:40 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	get_color(double iter, t_data *data, int max_iter)
{
	double	t;

	if (iter == max_iter)
		return (0);
	t = iter / (double)max_iter;
	if (data->palette == 0)
		return (palette_rgb(t));
	else if (data->palette == 1)
		return (palette_fire(iter));
	else if (data->palette == 2)
		return (palette_blue_white(iter));
	else
		return (palette_reverse_rgb(t));
}

void	render(t_data *data)
{
	int			x;
	int			y;
	const int	wh = 1080;
	long double	c_re;
	long double	c_im;

	x = 0;
	while (x < wh)
	{
		y = 0;
		data->x = x;
		while (y < wh)
		{
			data->y = y;
			c_re = (x - wh / 2.0) / (0.5 * data->zoom * wh) + data->offset_x;
			c_im = (y - wh / 2.0) / (0.5 * data->zoom * wh) + data->offset_y;
			fractal_choice(data, c_re, c_im);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
