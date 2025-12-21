/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:37:32 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 16:46:26 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_fractal(t_data *data, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fractal = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		data->fractal = 1;
		if (av[2] && av[3])
		{
			data->julia_re = (double)ft_atoi(av[2]) / 1000;
			data->julia_im = (double)ft_atoi(av[3]) / 1000;
		}
		else
		{
			data->julia_re = (double)0.2;
			data->julia_im = (double)0.3;
		}
	}
	else
		ft_exit(data);
}

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
	
	if (ac < 2)
		return (NULL);
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	init_fractal(data, av);
	data->zoom = 1.0;
    data->offset_x = -0.5;
    data->offset_y = 0.0;
    data->palette = 0.0;
	data->win = mlx_new_window(data->mlx, 1080, 1080, "fract-ol");
	init_image(data);
	return (data);
}
