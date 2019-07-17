/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:09:21 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 11:49:47 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s2;
	int		i;
	int		j;
	int		len;
	int		b;

	if (!s)
		return (NULL);
	b = 0;
	len = ft_strlen(s);
	i = 0;
	j = len - 1;
	while (s[i] && ft_del_white(s[i]))
		i++;
	while (j > 0 && ft_del_white(s[j]) && ++b)
		j--;
	if (len - i == 0)
		return (ft_strdup(""));
	if ((s2 = ft_strnew(len - i - b)) == NULL)
		return (NULL);
	b = 0;
	while (s[i] != '\0' && i <= j)
		s2[b++] = s[i++];
	s2[b] = '\0';
	return (s2);
}
