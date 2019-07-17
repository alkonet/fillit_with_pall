/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:24:07 by gloggins          #+#    #+#             */
/*   Updated: 2019/07/17 13:24:13 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	tetri_pos(t_etris **buf, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*buf)->x[j] = i % 5;
			(*buf)->y[j] = i / 5;
			j++;
		}
		i++;
	}
	(*buf)->x[4] = -1;
	(*buf)->y[4] = -1;
}

int		counter(char *str)
{
	int i;
	int col;

	i = 0;
	col = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			col++;
		i++;
	}
	return (col / 4);
}

t_etris		*stack_tetri(char *str)
{
	int		col_vo;
	int		add;
	t_etris *stack;
	t_etris *buf;

	add = 0;
	col_vo = counter(str);
	if (!(stack = (t_etris *)malloc(sizeof(t_etris))))
		return (NULL);
	buf = stack;
	while (col_vo > 0)
	{
		tetri_pos(&buf, ft_strsub(str, add, 20));
		if (col_vo == 1)
			return (stack);
		if (!(buf->next = (t_etris *)malloc(sizeof(t_etris))))
			return (NULL);
		buf = buf->next;
		col_vo--;
		add += 21;
	}
	buf->next = NULL;
	return (stack);
}

char	*stack_str(int fd)
{
	int		file;
	int		i;
	char	*str;
	char	a;

	i = 0;
	file = read(fd, &a, 1);
	if (file < 0)
		return (NULL);
	else
	{
		str = (char *)malloc(sizeof(char) * 546);
		while (file != '\0')
		{
			str[i] = a;
			i++;
			file = read(fd, &a, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
