/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:38:15 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 14:29:25 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res;
	size_t	c;

	i = 0;
	c = 0;
	while (dst[i] != '\0')
		i++;
	res = 0;
	while (src[res] != '\0')
		res++;
	if (size <= i)
		res = res + size;
	else
		res = res + i;
	while (src[c] != '\0' && i + 1 < size)
		dst[i++] = src[c++];
	dst[i] = '\0';
	return (res);
}
