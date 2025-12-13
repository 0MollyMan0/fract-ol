/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/13 15:01:02 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int main(void)
{
	void	*mlx;
	void	*win;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "MLX test");
	while (i++ < 10)
	{
		j = 0;
		while (j++ < 10)
			mlx_pixel_put(mlx, win, 200 + j, 150 + i, 0x00ff00);
	}
	ft_printf("MLX ready!\n");
	mlx_loop(mlx);
	return (0);
}