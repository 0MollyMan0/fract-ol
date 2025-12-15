/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/15 11:38:36 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	is_diverge(real, imag)
{
	int	max_iteration = 10;
	int	i;
	int	tmp_imag;
	int	tmp_real;

	i = 0;
	while (i < max_iteration)
	{
		tmp_imag = real * imag + imag * real;
		tmp_real = real * real + (imag * imag) * (-1);
		imag = tmp_imag;
		real = tmp_real;
		i++;
	}
	if (nb)
	{
		
	}
	
	
}

void put_pixel(char *addr, int line_len, int bpp, int x, int y, int color)
{
    char *pixel;

    pixel = addr + (y * line_len + x * (bpp / 8));
    *(unsigned int *)pixel = color;
}

int main(void)
{
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    int		x;
    int		y;
    int		win_width;
    int		win_height;
	
	win_width = 800;
	win_height = 600;
    mlx = mlx_init();
    win = mlx_new_window(mlx, win_width, win_height, "Fract-ol");

    img = mlx_new_image(mlx, win_width, win_height);
    addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
    y = 0;
    while (y < win_height)
    {
        x = 0;
        while (x < win_width)
        {
			if (is_diverge())
			{
				/* code */
			}
			
            put_pixel(addr, line_len, bpp, x, y, 0x0000FF);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}

