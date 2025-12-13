/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:16:28 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/08 09:30:18 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	ft_putnbr_hex(unsigned int nbr, char def_base);
int	ft_putp(unsigned long nbr);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_type(char type, va_list args);

#endif
