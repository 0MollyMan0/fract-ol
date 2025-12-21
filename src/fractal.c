/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:19:08 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 14:36:42 by anfouger         ###   ########.fr       */
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
