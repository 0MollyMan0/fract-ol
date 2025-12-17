/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:37:32 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/17 15:41:25 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    init_image(t_data *data)
{
    data->img.img = mlx_new_image(data->mlx, 1920, 1080);
    if (!data->img.img)
        ft_exit(data);

    data->img.addr = mlx_get_data_addr(
        data->img.img,
        &data->img.bpp,
        &data->img.line_len,
        &data->img.endian
    );
}

t_data	*ft_init_mlx(void)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	data->zoom = 1;
    data->offset_x = 0;
    data->offset_y = 0;
	data->win = mlx_new_window(data->mlx, 1920, 1080, "fract-ol");
	init_image(data);
	return (data);
}