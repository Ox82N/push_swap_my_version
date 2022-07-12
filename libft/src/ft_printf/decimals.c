/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:23:34 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/03 08:23:45 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		nbr = 147483648;
		len += ft_putstr("-2");
	}
	if (nbr < 0)
	{
		nbr *= -1;
		len += ft_putchar('-');
	}
	if (nbr < 10)
		len += ft_putchar(nbr + 48);
	else
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += ft_putchar(nbr + 48);
	else
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	return (len);
}
