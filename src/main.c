/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:41:22 by pallspic          #+#    #+#             */
/*   Updated: 2019/07/09 18:23:25 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void 			clr_parts(t_etris *parts, short amount)
{
	t_etris	*buff;

	buff = parts;
	while (amount--)
	{
		buff->x[4] = -1;
		buff->y[4] = -1;
		if (buff->next)
			buff = buff->next;
	}
}


short			fl_fill(t_etris pt, char **map, char letter, unsigned short size)
{
	short	xn;
	short	yn;
	char 	*pointer[4];
	short	i;

	xn = pt.x[4];
	yn = pt.y[4];

	i = 0;
	while (i < 4)
	{
		if (!map[xn + pt.y[i]][yn + pt.x[i]] ||
			map[xn + pt.y[i]][yn + pt.x[i]] != '.')
			return (0);
		pointer[i] = &map[xn + pt.y[i]][yn + pt.x[i]];
		i++;
	}
	while (--i >= 0)
		*(pointer[i]) = letter;
	print_map(map, size);
	return (1);
}


short 			fl_try(t_etris *parts, char **map, unsigned short size, char letter)
{
	if (!parts)
		return (1);
	if (parts->x[4] == -1 && parts->y[4] == -1)
	{
		parts->x[4] = 0;
		parts->y[4] = 0;
	}
	while (parts->x[4] < 4)
	{
		while (parts->y[4] < 4)
		{
			if (map[parts->x[4]][parts->y[4]] == '.')
				if (fl_fill(*parts, map, letter, size))
					if (fl_try(parts->next, copy_map(map, size), size, letter + 1))
					{
						print_map(map, size);
						free(map);
						return (1);
					}
			parts->y[4]++;
		}
		parts->x[4]++;
	}
	free(map);
	return (0);
}

int				fillit(short amount, t_etris *parts)
{
	unsigned short	size;
	int				result;
	char			**map;

	result = 10;
	size = fl_mapsize(amount);
	while (result != 1)
		if (!(map = create_map(size)))
			return (-1);
		else if (!(result = fl_try(parts, map, size, 'A')) && size++)
			clr_parts(parts, amount);
	return (1);
}