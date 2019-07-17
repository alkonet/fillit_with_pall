/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:19:18 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/08 13:24:12 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str[i] = f((unsigned int)i, s[i]);
	str[i] = '\0';
	return (str);
}
