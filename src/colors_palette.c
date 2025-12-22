/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_palette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:06:08 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/22 10:58:09 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	violet_to_red(double t)
{
	const int	r = 255;
	const int	g = 0;
	int			b;

	b = 255 - (t * 255);
	return (r << 16 | g << 8 | b);
}

int	palette_rgb(double t)
{
	double zone;
	double t_local; 

	zone = t * 6;
	t_local = zone - (int)zone;
	if (zone < 1)
		return cyan_to_blue(t_local);
	else if (zone >= 1 && zone < 2)
		return blue_to_violet(t_local);
	else if (zone >= 2 && zone < 3)
		return violet_to_red(t_local);
	else if (zone >= 3 && zone < 4)
		return red_to_yellow(t_local);
	else if (zone >= 4 && zone < 5)
		return yellow_to_green(t_local);
	return green_to_cyan(t_local);
}

int	palette_reverse_rgb(double t)
{
	double zone;
	double t_local; 

	zone = t * 6;
	t_local = zone - (int)zone;
	if (zone < 1)
		return blue_to_violet(t_local);
	else if (zone >= 1 && zone < 2)
		return violet_to_red(t_local);
	else if (zone >= 2 && zone < 3)
		return red_to_yellow(t_local);
	else if (zone >= 3 && zone < 4)
		return yellow_to_green(t_local);
	else if (zone >= 4 && zone < 5)
		return green_to_cyan(t_local);
	return cyan_to_blue(t_local);
}

int	palette_blue_white(double iter)
{
	const int	r = iter * 255 / 100;
	const int	g = iter * 255 / 100;
	const int	b = 255;
	
	return (r << 16 | g << 8 | b);
}

int	palette_fire(double iter)
{
	const int	r = iter * 255 / 50;
	const int	g = iter * 255 / 100;
	const int	b = iter * 255 / 200;
	
	return (r << 16 | g << 8 | b);
}
