/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:32:44 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/01 23:32:56 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			z;
	unsigned char	*string;
	unsigned char	chr;

	string = (unsigned char *)str;
	chr = (unsigned char)c;
	z = 0;
	while (z < n)
	{
		if (*string == chr)
			return ((void *)string);
		string++;
		z++;
	}
	return (0);
}
