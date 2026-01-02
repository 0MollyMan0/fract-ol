/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:28:35 by anfouger          #+#    #+#             */
/*   Updated: 2026/01/02 14:08:31 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	change_palette(int keycode, t_data *data)
{
	if (keycode == '1')
	{
		if (data->palette == 0)
			data->palette = 3;
		else
			data->palette--;
	}
	else if (keycode == '2')
	{
		if (data->palette == 3)
			data->palette = 0;
		else
			data->palette++;
	}
}

static void	change_julia(int keycode, t_data *data)
{
	if (keycode == 'c')
		data->julia_im -= 0.001;
	else if (keycode == 'v')
		data->julia_im += 0.001;
	else if (keycode == 'z')
		data->julia_re -= 0.001;
	else if (keycode == 'x')
		data->julia_re += 0.001;
}

static void	change_fractal(int keycode, t_data *data)
{
	if (keycode == '3')
	{
		if (data->fractal == 0)
			data->fractal = 2;
		else
			data->fractal--;
	}
	else if (keycode == '4')
	{
		if (data->fractal == 2)
			data->fractal = 0;
		else
			data->fractal++;
	}
}

static void	move(int keycode, t_data *data)
{
	if (keycode == 65361 || keycode == 'a')
		data->offset_x -= 0.4 / data->zoom;
	else if (keycode == 65363 || keycode == 'd')
		data->offset_x += 0.4 / data->zoom;
	else if (keycode == 65362 || keycode == 'w')
		data->offset_y -= 0.4 / data->zoom;
	else if (keycode == 65364 || keycode == 's')
		data->offset_y += 0.4 / data->zoom;
}

int	ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	else if ((keycode >= 65361 && keycode <= 65364) || keycode == 'w'
		|| keycode == 'a' || keycode == 's' || keycode == 'd')
		move(keycode, data);
	else if (keycode == '1' || keycode == '2')
		change_palette(keycode, data);
	else if (keycode == '3' || keycode == '4')
		change_fractal(keycode, data);
	else if (keycode == 'z' || keycode == 'x'
		|| keycode == 'c' || keycode == 'v')
		change_julia(keycode, data);
	render(data);
	return (0);
}
