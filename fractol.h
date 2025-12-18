/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:04:04 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/18 14:38:52 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

typedef struct s_data
{
	void	*win;
	void	*mlx;
	t_img	img;
	double	zoom;
	double	offset_x;
	double	offset_y;
} t_data;

/*---Event---*/
int		ft_key_pressed(int keycode, t_data *param);
int		ft_exit(t_data *param);

/*---Init---*/
t_data	*ft_init_mlx(void);

/*---Visual---*/
void	render(t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);

/*---Fractal---*/
int mandelbrot(double c_re, double c_im);

#endif