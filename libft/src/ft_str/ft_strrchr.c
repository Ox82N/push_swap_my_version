/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:18 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/02 00:37:33 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;
	int		s_len;

	s_len = ft_strlen(s);
	pointer = (char *)s + s_len - 1;
	if (c == '\0')
	{
		pointer++;
		return ((char *)pointer);
	}
	while (s_len != '\0')
	{
		if ((unsigned char)*pointer == (unsigned char)c)
		{
			return ((char *)pointer);
		}
		s_len--;
		pointer--;
	}
	return (NULL);
}
