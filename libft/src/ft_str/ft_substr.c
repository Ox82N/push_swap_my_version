/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:54 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/02 00:38:04 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s2;

	if (!s)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s) && s[start + i])
	{
		i++;
	}
	j = 0;
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (j < i && start < ft_strlen(s))
	{
		s2[j] = s[start + j];
		j++;
	}
	s2[i] = '\0';
	return (s2);
}
