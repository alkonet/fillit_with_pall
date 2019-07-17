/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:27:42 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 14:22:23 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*sorc;

	dest = (char *)dst;
	sorc = (const char *)src;
	if (n == 0)
		return (dst);
	while (n--)
		*dest++ = *sorc++;
	return (dst);
}
