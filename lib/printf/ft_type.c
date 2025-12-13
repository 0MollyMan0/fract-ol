/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:21:42 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 11:11:32 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_type(char type, va_list args)
{
	int	res;

	if (type == '%')
		res = ft_putchar('%');
	else if (type == 'c')
		res = ft_putchar(va_arg(args, int));
	else if (type == 's')
		res = ft_putstr(va_arg(args, char *));
	else if (type == 'i' || type == 'd')
		res = ft_putnbr(va_arg(args, int));
	else if (type == 'p')
		res = ft_putp(va_arg(args, unsigned long));
	else if (type == 'x' || type == 'X')
		res = ft_putnbr_hex(va_arg(args, unsigned int), type);
	else if (type == 'u')
		res = ft_putnbr_u(va_arg(args, unsigned int));
	else
		res = 0;
	return (res);
}
