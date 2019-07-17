/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:14:50 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/09 12:00:50 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*f;
	int		i;
	int		res;

	if (!s1 && !s2)
		return (NULL);
	if ((i = 0) == 0 && s1)
		while (s1[i] != '\0')
			i++;
	res = i + 1;
	if ((i = 0) == 0 && s2)
		while (s2[i] != '\0')
			i++;
	res = res + i + 1;
	i = -1;
	if ((f = malloc(sizeof(char) * res)) == NULL)
		return (NULL);
	res = 0;
	while (s1 && s1[++i] != '\0')
		f[res++] = s1[i];
	i = -1;
	while (s2 && s2[++i] != '\0')
		f[res++] = s2[i];
	f[res] = '\0';
	return (f);
}
