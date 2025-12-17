/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/17 11:16:28 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

typedef struct s_data
{
	void	*win;
	void	*mlx;
} t_data;

int	key_pressed(int keycode, t_data *param)
{
	ft_printf("key press\n");
	if (keycode == 65307)
	{
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		free(param);
		exit(0);
	}
	return (0);
}

int	ft_exit(t_data *param)
{
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	free(param);
	exit(0);
	return(0);    
}

int	main(void)
{
	t_data *test;

	test = malloc(sizeof(t_data));
	test->mlx = mlx_init();
    
	if (!test->mlx)
		return (1);

	test->win = mlx_new_window(test->mlx, 1080, 720, "mlx_hook test");
	if (!test->win)
		return (1);
	mlx_hook(test->win, 2, 1L << 0, key_pressed, test);
	mlx_hook(test->win, 17, 0, ft_exit, test);
	mlx_loop(test->mlx);
	return (0);
}


