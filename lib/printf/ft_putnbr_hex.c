/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:52:04 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 11:11:23 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned long	ft_strlen(char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_putnbr_base_u(unsigned long nbr, char *base)
{
	int				count;
	char			c;
	unsigned long	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		count += ft_putnbr_base_u(nbr / base_len, base);
	c = base[nbr % base_len];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_hex(unsigned int nbr, char def_base)
{
	int		count;

	if (def_base == 'X')
		count = ft_putnbr_base_u(nbr, "0123456789ABCDEF");
	else
		count = ft_putnbr_base_u(nbr, "0123456789abcdef");
	return (count);
}
