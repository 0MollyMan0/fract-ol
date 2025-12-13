/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:01:48 by anfouger          #+#    #+#             */
/*   Updated: 2025/10/30 16:11:10 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr(int nb)
{
	char	w;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		nb *= -1;
	}
	if (nb / 10)
		count += ft_putnbr(nb / 10);
	w = nb % 10 + '0';
	count++;
	write (1, &w, 1);
	return (count);
}
