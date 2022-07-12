/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:38 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/02 00:37:49 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	s_len;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		count = 0;
		s_len = ft_strlen(s1);
		while (s1[count] && ft_strchr(set, s1[count]))
			count++;
		while (s1[s_len - 1] && ft_strchr(set, s1[s_len - 1]) && s_len > count)
			s_len--;
		str = (char *)malloc(sizeof(char) * (s_len - count + 1));
		if (str)
			ft_strlcpy(str, &s1[count], s_len - count + 1);
	}
	return (str);
}
