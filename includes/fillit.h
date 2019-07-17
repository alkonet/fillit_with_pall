/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:21:35 by gloggins          #+#    #+#             */
/*   Updated: 2019/07/09 11:21:37 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include "stdlib.h"
# include <string.h>
# include <unistd.h>
# include "fcntl.h"
# include <stdio.h>

typedef struct		s_tetri
{
	short			x[5];
	short			y[5];
	struct s_tetri	*next;
}					t_etris;

char	*stack_str(int fd);
t_etris	*stack_tetri(char *str);
int		counter(char *str);
void	tetri_pos(t_etris **buf, char *str);
int		fillit(short amount, t_etris *parts);
short 	fl_try(t_etris *parts, char **map, unsigned short size, char letter);
void	print_map(char **map, unsigned short size);
char 	**copy_map(char **map, unsigned short size);
short	fl_fill(t_etris pt, char **map, char letter, unsigned short size);
char 	**create_map(unsigned short size);
void 	clr_parts(t_etris *parts, short amount);
unsigned short	fl_mapsize(short amount);
int		main(int argc, char **argv);
int		check_str(char *stock);
int		valid_char(char *stock, int j);
int		valid_link(char *stock, int j);
void 	del_more(t_etris *tetri);
#endif
