/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:10:58 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/05 15:47:18 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bt;

	i = 0;
	bt = (unsigned char*)s;
	while (++i <= n)
		if (*(bt++) == (unsigned char)c)
			return ((void*)--bt);
	return (NULL);
}
