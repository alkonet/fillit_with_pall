/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:57:42 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/08 11:57:55 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;
	char	*tmp;

	if ((tmp = malloc(sizeof(char) * len)) == NULL)
		return (dst);
	if (len <= 0)
		return (dst);
	i = -1;
	s1 = (char*)src;
	s2 = (char*)dst;
	while (++i < len)
		tmp[i] = s1[i];
	i = -1;
	while (++i < len)
		s2[i] = tmp[i];
	free(tmp);
	return (s2);
}
