/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:19:08 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/22 11:32:49 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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

double	julia(double c_re, double c_im, t_data *data)
{
	double	tmp;
	double	k_im;
	double	k_re;
	double	i;

	i = 0;
	k_re = data->julia_re;
	k_im = data->julia_im;
	while (i < 100)
	{
		tmp = c_re * c_re - c_im * c_im + k_re;
		c_im = 2 * c_re * c_im + k_im;
		c_re = tmp;
		if (c_re * c_re + c_im * c_im > 4)
			break;
		i++;
	}
	if (i == 100)
		return (i);
	double modulus = sqrt(c_re * c_re + c_im * c_im);
	return i + 1 - log(log(modulus)) / log(2);
}

double	burning_ship(double c_re, double c_im)
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
		z_re = fabs(z_re);
		z_im = fabs(z_im);
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

void	fractal_choice(t_data *data, double c_re, double c_im)
{
	if (data->fractal == 0)
		put_pixel(&data->img, data->x, data->y, 
			get_color(mandelbrot(c_re, c_im), data));
	else if (data->fractal == 1)
		put_pixel(&data->img, data->x, data->y, 
			get_color(julia(c_re, c_im, data), data));
	else if (data->fractal == 2)
		put_pixel(&data->img, data->x, data->y, 
			get_color(burning_ship(c_re, c_im), data));
}
