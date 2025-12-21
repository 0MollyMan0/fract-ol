/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/21 15:24:18 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	error_param(void)
{
	write(1, "Wrong parameters !!!\n", 21);
	write(1, "You can choose between \"julia\" and \"mandelbrot\"\n", 48);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_mlx(ac, av);
	if (!data)
	{
		error_param();
		return (0);
	}
	if (!data->mlx)
	{
		ft_exit(data);
		return (1);	
	}
	render(data);
	mlx_hook(data->win, 2, 1L << 0, ft_key_pressed, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_hook, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_loop(data->mlx);
	return (0);
}


