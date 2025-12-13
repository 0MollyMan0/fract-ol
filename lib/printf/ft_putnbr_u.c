/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:57:43 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 10:39:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	char	w;
	int		count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_u(nb / 10);
	w = (nb % 10) + '0';
	count++;
	write (1, &w, 1);
	return (count);
}
