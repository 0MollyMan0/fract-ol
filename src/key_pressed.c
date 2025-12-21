/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:28:35 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 15:31:41 by anfouger         ###   ########.fr       */
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
	if (keycode == 50)
	{
		if (data->palette == 8)
			data->palette = 0;
		else
			data->palette++;
	}
}

static void	move(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->offset_x -= 0.4 / data->zoom;
	else if (keycode == 65363)
		data->offset_x += 0.4 / data->zoom;
	else if (keycode == 65362)
		data->offset_y -= 0.4 / data->zoom;																	
	else if (keycode == 65364)
		data->offset_y += 0.4 / data->zoom;
}

int	ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	if (keycode >= 65361 && keycode <= 65364)
		move(keycode, data);
	if (keycode == 49 || keycode == 50)
		change_palette(keycode, data);	
	render(data);
	return (0);
}
