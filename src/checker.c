/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:11:07 by gloggins          #+#    #+#             */
/*   Updated: 2019/07/11 13:11:09 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void 	del_more(t_etris *tetri)
{
	short	i;


	while (tetri)
	{
		i = 3;
		while (i >= 0)
		{
			tetri->x[i] -= tetri->x[0];
			tetri->y[i] -= tetri->y[0];
			i--;
		}
		tetri = tetri->next;
	}
}

int		valid_link(char *stock, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && stock[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && stock[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && stock[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && stock[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		valid_char(char *stock, int j)
{
	int hash;
	int dot;
	int nl;
	int i;

	i = 0;
	hash = 0;
	dot = 0;
	nl = 0;
	while (i + j < 20 + j && stock[i + j] != '\0')
	{
		if (stock[i + j] == '#')
			hash++;
		if (stock[i + j] == '.')
			dot++;
		if (stock[i + j] == '\n')
			nl++;
		i++;
	}
	if (hash == 4 && dot == 12 && nl == 4)
		return (1);
	return (0);
}

int		check_str(char *stock)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stock[i + j] != '\0')
	{
		if (!(valid_link(stock, j) && valid_char(stock, j)))
			return (0);
		i = 19;
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\0')
			return (1);
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\n'
				&& (stock[i + j + 2] == '.' || stock[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	short	i;
	char	*stock;
	t_etris	*tetri;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	stock = stack_str(fd);
	if (!check_str(stock))
	{
		write(1, "error", 5);
		close(fd);
		return (0);
	}
	tetri = stack_tetri(stock);
	i = counter(stock);
	del_more(tetri);
	fillit(i, tetri);
	close(fd);
	return (0);
}