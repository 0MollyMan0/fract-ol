/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:37:32 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/17 12:27:46 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    init_image(t_data *mlx)
{
    mlx->img.img = mlx_new_image(mlx->mlx, 800, 600);
    if (!mlx->img.img)
        ft_exit(mlx);

    mlx->img.addr = mlx_get_data_addr(
        mlx->img.img,
        &mlx->img.bpp,
        &mlx->img.line_len,
        &mlx->img.endian
    );
}

t_data	*ft_init_mlx(void)
{
	t_data	*mlx;
	
	mlx = malloc(sizeof(t_data));
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx, 1080, 720, "fract-ol");
	init_image(mlx);
	return (mlx);
}