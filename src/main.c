/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/17 09:16:00 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int key_pressed(int keycode, void *param)
{
    (void)param;
    write(1, "key press\n", 15);
    if (keycode == 65307)
        exit(0);
    return (0);
}

int ft_exit(void *param)
{
    (void)param;
    exit(0);
    return(0);    
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    
    if (!mlx)
        return (1);

    win = mlx_new_window(mlx, 800, 600, "mlx_hook test");
    if (!win)
        return (1);
    mlx_hook(win, 2, 1L << 0, key_pressed, NULL);
    mlx_hook(win, 17, 0, ft_exit, NULL);
    mlx_loop(mlx);
    return (0);
}


