/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:34:01 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/01 23:34:11 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str2;

	i = 0;
	str2 = b;
	while (i < len)
	{
		str2[i] = (char)c;
		i++;
	}
	return (str2);
}
