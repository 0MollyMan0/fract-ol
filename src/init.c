/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:37:32 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 15:22:41 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    init_image(t_data *data)
{
    data->img.img = mlx_new_image(data->mlx, 1080, 1080);
    if (!data->img.img)
        ft_exit(data);

    data->img.addr = mlx_get_data_addr(
        data->img.img,
        &data->img.bpp,
        &data->img.line_len,
        &data->img.endian
    );
}

t_data	*ft_init_mlx(int ac, char **av)
{
	t_data	*data;
	
	if (ac != 2)
		return (NULL);
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fractal = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fractal = 1;
	else
	{
		ft_exit(data);
		return (NULL);
	}
	data->zoom = 1.0;
    data->offset_x = -0.5;
    data->offset_y = 0.0;
    data->palette = 0.0;
	data->win = mlx_new_window(data->mlx, 1080, 1080, "fract-ol");
	init_image(data);
	return (data);
}
