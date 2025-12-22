/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:13:22 by anfouger          #+#    #+#             */
/*   Updated: 2025/12/22 13:05:20 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_verif_num(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9')
			&& !(arg[i] == '-' && i == 0)
			&& !(arg[i] == '+' && i == 0))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_verif_max(char *s)
{
	long long	n;
	int			sign;

	n = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		n = n * 10 + (*s - '0');
		if (sign == 1 && n > INT_MAX)
			return (0);
		if (sign == -1 && - n < INT_MIN)
			return (0);
		s++;
	}
	return (1);
}
