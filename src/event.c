/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:19:37 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/17 14:55:51 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_key_pressed(int keycode, t_data *data)
{
	ft_printf("key press\n");
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 65361)
		data->offset_x -= 10;
	if (keycode == 65363)
		data->offset_x += 10;
	if (keycode == 65362)
		data->offset_y -= 10;
	if (keycode == 65364)
		data->offset_y += 10;
	render(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;

	if (button == 4)
		data->zoom *= 1.1;
	if (button == 5)
		data->zoom /= 1.1;

	render(data);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
	return(0);    
}