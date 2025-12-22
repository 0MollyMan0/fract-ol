/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:04:04 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/22 12:41:59 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_data
{
	void		*win;
	void		*mlx;
	t_img		img;
	double		julia_re;
	double		julia_im;
	long double	zoom;
	long double	offset_x;
	long double	offset_y;
	double		palette;
	int			fractal;
	int			x;
	int			y;
}					t_data;

/*---Event---*/
int		mouse_hook(int button, int x, int y, t_data *data);
int		ft_key_pressed(int keycode, t_data *param);
int		ft_exit(t_data *param);

/*---Init---*/
t_data	*ft_init_mlx(int ac, char **av);

/*---Verif---*/
int		ft_verif_num(char *arg);
void	error_param(void);

/*---Colors---*/
int		palette_blue_white(double iter);
int		palette_reverse_rgb(double t);
int		palette_rgb(double t);
int		palette_fire(double iter);
int		violet_to_red(double t);
int		red_to_yellow(double t);
int		yellow_to_green(double t);
int		green_to_cyan(double t);
int		cyan_to_blue(double t);
int		blue_to_violet(double t);

/*---Visual---*/
void	render(t_data *data);
int		get_color(double iter, t_data *data, int max_iter);
void	put_pixel(t_img *img, int x, int y, int color);

/*---Fractal---*/
void	fractal_choice(t_data *data, double c_re, double c_im);

#endif