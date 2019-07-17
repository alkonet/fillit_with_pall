/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:01:15 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 12:17:57 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int res;
	int	min;
	int count;

	min = 1;
	res = 0;
	count = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		min = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - 48);
		str++;
		count++;
	}
	if (count >= 19 && min == -1)
		return (0);
	else if (count >= 19 && min == 1)
		return (-1);
	return (res * min);
}
