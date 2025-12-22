/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/22 11:20:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	error_param(void)
{
	write(1, "!!! Wrong parameters !!!\n", 25);
	write(1, "You can choose between \"julia\", \"mandelbrot\" ", 45);
	write(1, "\"burning_ship\".\n", 16);
	write(1, "If you choose the Julia fractal, you must enter the real", 56);
	write(1, " part and the imaginary part. \nThe values must be entered", 57);
	write(1, " as integers (e.g. \"115\" and \"754\"), which will", 47);
	write(1, " be interpreted as 0.115 + 0.754i.\n", 35);
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


