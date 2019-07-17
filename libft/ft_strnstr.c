/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:16:38 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/05 15:36:36 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t j;

	if (!*find)
		return ((char*)str);
	j = 0;
	while (str[j] != '\0' && j < len)
	{
		if (str[j] == find[0])
		{
			i = 1;
			while (find[i] != '\0' && str[i + j] == find[i] && (i + j) < len)
				i++;
			if (find[i] == '\0')
				return ((char*)&str[j]);
		}
		j++;
	}
	return (0);
}
