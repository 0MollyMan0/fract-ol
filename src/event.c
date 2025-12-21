/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:19:37 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 14:58:42 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	change_palette(int keycode, t_data *data)
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

int	ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 65361)
		data->offset_x -= 0.4 / data->zoom;
	if (keycode == 65363)
		data->offset_x += 0.4 / data->zoom;
	if (keycode == 65362)
		data->offset_y -= 0.4 / data->zoom;																	
	if (keycode == 65364)
		data->offset_y += 0.4 / data->zoom;
	if (keycode == 49 || keycode == 50)
		change_palette(keycode, data);	
	render(data);
	return (0);
}

int mouse_hook(int button, int x, int y, t_data *data)
{
	double	mouse_re;
	double	mouse_im;
	double	new_re;
	double	new_im;

	if (button != 4 && button != 5)
		return (0);
	mouse_re = (x - 1080 / 2.0) / (0.5 * data->zoom * 1080) + data->offset_x;
	mouse_im = (y - 1080 / 2.0) / (0.5 * data->zoom * 1080) + data->offset_y;
	if (button == 4)
		data->zoom *= 1.1;
	if (button == 5)
		data->zoom /= 1.1;
	new_re = (x - 1080 / 2.0) / (0.5 * data->zoom * 1080) + data->offset_x;
	new_im = (y - 1080 / 2.0) / (0.5 * data->zoom * 1080) + data->offset_y;
	data->offset_x += mouse_re - new_re;
	data->offset_y += mouse_im - new_im;
	render(data);
	return (0);
}

int	ft_exit(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
	return(0);    
}