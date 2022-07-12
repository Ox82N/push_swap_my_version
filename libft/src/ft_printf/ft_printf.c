/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:23:56 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/03 08:24:12 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_check_flag(char c, va_list a)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(a, int));
	if (c == 's')
		len += ft_putstr(va_arg(a, char *));
	if (c == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putadd(va_arg(a, unsigned long));
	}
	if (c == 'd')
		len += ft_putnbr(va_arg(a, int));
	if (c == 'i')
		len += ft_putnbr(va_arg(a, int));
	if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(a, unsigned int));
	if (c == 'x' || c == 'X')
		len += ft_putnbr_hex(va_arg(a, int), c);
	if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	a;
	int		len;
	int		i;

	va_start(a, s);
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_check_flag(s[i], a);
			i++;
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(a);
	return (len);
}
