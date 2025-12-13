/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/13 15:40:50 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void put_pixel(char *addr, int line_len, int bpp, int x, int y, int color)
{
    char *pixel;

    pixel = addr + (y * line_len + x * (bpp / 8));
    *(unsigned int *)pixel = color;
}

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int   bpp;
    int   line_len;
    int   endian;
    int   x;
    int   y;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Image MLX");

    img = mlx_new_image(mlx, 400, 300);
    addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
    y = 0;
    while (y < 300)
    {
        x = 0;
        while (x < 400)
        {
            put_pixel(addr, line_len, bpp, x, y, 0x0000FF);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}

