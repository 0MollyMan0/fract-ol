/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:19:08 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 15:17:27 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fractal_choice(t_data *data, int x, int y, double c_re, double c_im)
{
	if (data->fractal == 0)
		put_pixel(&data->img, x, y, get_color(mandelbrot(c_re, c_im), data));
	else if (data->fractal == 1)
		put_pixel(&data->img, x, y, get_color(julia(c_re, c_im), data));
}

double	mandelbrot(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	tmp;
	double	i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (i < 100)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = (z_im * z_re) * 2 + c_im;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > 4)
			break;
		i++;
	}
	if (i == 100)
		return (i);
	double modulus = sqrt(z_re * z_re + z_im * z_im);
	return i + 1 - log(log(modulus)) / log(2);
}

double	julia(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	tmp;
	double	i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (i < 100)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = (z_im * z_re) * 2 + c_im;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > 4)
			break;
		i++;
	}
	if (i == 100)
		return (i);
	return (i + (4.0 - (z_re * z_re + z_im * z_im) / 4.0));
}
