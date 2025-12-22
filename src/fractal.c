/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:19:08 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/22 11:54:54 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static double	mandelbrot(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	double	i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (i < max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = (z_im * z_re) * 2 + c_im;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > 4)
			break;
		i++;
	}
	if (i == max_iter)
		return (i);
	double modulus = sqrt(z_re * z_re + z_im * z_im);
	return i + 1 - log(log(modulus)) / log(2);
}

static double	julia(double c_re, double c_im, t_data *data, int max_iter)
{
	double	tmp;
	double	k_im;
	double	k_re;
	double	i;

	i = 0;
	k_re = data->julia_re;
	k_im = data->julia_im;
	while (i < max_iter)
	{
		tmp = c_re * c_re - c_im * c_im + k_re;
		c_im = 2 * c_re * c_im + k_im;
		c_re = tmp;
		if (c_re * c_re + c_im * c_im > 4)
			break;
		i++;
	}
	if (i == max_iter)
		return (i);
	double modulus = sqrt(c_re * c_re + c_im * c_im);
	return i + 1 - log(log(modulus)) / log(2);
}

static double	burning_ship(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	double	i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (i < max_iter)
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
	if (i == max_iter)
		return (i);
	double modulus = sqrt(z_re * z_re + z_im * z_im);
	return i + 1 - log(log(modulus)) / log(2);
}

void	fractal_choice(t_data *data, double c_re, double c_im)
{
	int max_iter;
	max_iter = 100 * data->zoom;
	if (max_iter > 1000)
		max_iter = 1000;
	if (data->fractal == 0)
		put_pixel(&data->img, data->x, data->y, 
			get_color(mandelbrot(c_re, c_im, max_iter), data, max_iter));
	else if (data->fractal == 1)
		put_pixel(&data->img, data->x, data->y, 
			get_color(julia(c_re, c_im, data, max_iter), data, max_iter));
	else if (data->fractal == 2)
		put_pixel(&data->img, data->x, data->y, 
			get_color(burning_ship(c_re, c_im, max_iter), data, max_iter));
}
