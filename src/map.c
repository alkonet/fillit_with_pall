/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:59:26 by gloggins          #+#    #+#             */
/*   Updated: 2019/07/17 13:59:29 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

unsigned short	fl_mapsize(short amount)
{
	short	size;

	size = 2;
	while (size * size < amount * 4)
		size++;
	return (size);
}

char 			**create_map(unsigned short size)
{
	char **result;
	short i;
	short j;

	i = 0;
	if (!(result = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
		if (!(result[i++] = (char *)malloc(sizeof(char) * size)))
			return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			result[i][j] = '.';
	}
	return (result);
}

char 			**copy_map(char **map, unsigned short size)
{
	char **copy;
	short	i;
	short	j;

	i = -1;
	copy = create_map(size);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			copy[i][j] = map[i][j];
	}
	return (copy);
}

void			print_map(char **map, unsigned short size)
{
	short	i;

	i = -1;
	while (++i < size)
		ft_putendl(map[i]);
}
