/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:25:03 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 12:23:07 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(unsigned int nb)
{
	unsigned int	s;

	s = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		s++;
	}
	return (s + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	nb;
	unsigned int	s;

	i = 0;
	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	s = (unsigned int)ft_size(nb);
	if (!(str = (char*)malloc(sizeof(char) * (s + 1 + (ft_pos_neg(n))))))
		return (NULL);
	if (n < 0 && (str[i] = '-'))
		s++;
	i = s - 1;
	while (nb >= 10)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[i] = nb % 10 + '0';
	str[s] = '\0';
	return (str);
}
