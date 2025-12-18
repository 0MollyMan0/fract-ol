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

static int	get_color(int i)
{
	if (i == 100)
		return (0x00000000);
	return (0x0000FF00 + i * 500);
}

void	render(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1080)
	{
		y = 0;
		while (y < 1080)
		{
            double c_re = (x / (double)1080) * 3.0 - 2.0;
            double c_im = (y / (double)1080) * 3.0 - 1.5;
            int i = mandelbrot(c_re, c_im);
            int color = get_color(i);
			put_pixel(&data->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

