/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:14:34 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 13:28:29 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	red_to_yellow(double t)
{
	const int	r = 255;
	int			g;
	const int	b = 0;

	g = t * 255;
	return (r << 16 | g << 8 | b);
}

int	yellow_to_green(double t)
{
	int			r;
	const int	g = 255;
	const int	b = 0;

	r = 255 - (t * 255);
	return (r << 16 | g << 8 | b);
}

int	green_to_cyan(double t)
{
	const int	r = 0;
	const int	g = 255;
	int			b;

	b = t * 255;
	return (r << 16 | g << 8 | b);
}

int	cyan_to_blue(double t)
{
	const int	r = 0;
	int			g;
	const int	b = 255;

	g = 255 - (t * 255);
	return (r << 16 | g << 8 | b);
}

int	blue_to_violet(double t)
{
	int			r;
	const int	g = 0;
	const int	b = 255;

	r = t * 255;
	return (r << 16 | g << 8 | b);
}
