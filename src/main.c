/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/17 12:38:17 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void put_pixel(t_img *img, int x, int y, int color)
{
    char *pixel;

    pixel = img->addr
        + (y * img->line_len
        + x * (img->bpp / 8));

    *(unsigned int *)pixel = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_data *mlx;
	int		y;
	int		x;
	int		r;
	int		g;
	int		b;

	y = 0;
	mlx = ft_init_mlx();
	if (!mlx->mlx)
	{
		ft_exit(mlx);
		return (1);	
	}
	mlx_hook(mlx->win, 2, 1L << 0, ft_key_pressed, mlx);
	mlx_hook(mlx->win, 17, 0, ft_exit, mlx);
	while (y < 600)
	{
		x = 0;
		r = 0;
		g = 255;
		b = 0;
		while (x < 800)
		{
			put_pixel(&mlx->img, x, y, create_trgb(1, r++, g--, b++));
			x++;	
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}


