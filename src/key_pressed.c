/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:28:35 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/22 09:58:04 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	change_palette(int keycode, t_data *data)
{
	if (keycode == 49)
	{
		if (data->palette == 0)
			data->palette = 8;
		else
			data->palette--;	
	}
	else if (keycode == 50)
	{
		if (data->palette == 8)
			data->palette = 0;
		else
			data->palette++;
	}
}

static void	change_julia(int keycode, t_data *data)
{
	if (keycode == 99)
		data->julia_im -= 0.001;	
	else if (keycode == 118)
		data->julia_im += 0.001;
	else if (keycode == 122)
		data->julia_re -= 0.001;
	else if (keycode == 120)
		data->julia_re += 0.001;
}

static void	change_fractal(int keycode, t_data *data)
{
	if (keycode == 51)
	{
		if (data->fractal == 0)
			data->fractal = 1;
		else
			data->fractal--;	
	}
	else if (keycode == 52)
	{
		if (data->fractal == 1)
			data->fractal = 0;
		else
			data->fractal++;
	}
}

static void	move(int keycode, t_data *data)
{
	if (keycode == 65361 || keycode == 97)
		data->offset_x -= 0.4 / data->zoom;
	else if (keycode == 65363 || keycode == 100)
		data->offset_x += 0.4 / data->zoom;
	else if (keycode == 65362 || keycode == 119)
		data->offset_y -= 0.4 / data->zoom;																	
	else if (keycode == 65364 || keycode == 115)
		data->offset_y += 0.4 / data->zoom;
}

int	ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	else if ((keycode >= 65361 && keycode <= 65364) || keycode == 119 
		|| keycode == 97 || keycode == 115 || keycode == 100)
		move(keycode, data);
	else if (keycode == 49 || keycode == 50)
		change_palette(keycode, data);
	else if (keycode == 51 || keycode == 52)
		change_fractal(keycode, data);
	else if (keycode == 122 || keycode == 120 
		|| keycode == 99 || keycode == 118)
		change_julia(keycode, data);
	render(data);
	return (0);
}
