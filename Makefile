# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloggins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 11:24:49 by gloggins          #+#    #+#              #
#    Updated: 2019/07/09 11:24:51 by gloggins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit 

SRC	:=  ./src/main.c \
        ./src/checker.c \
        ./src/map.c \
        ./src/valid.c

INC	:= ./includes

LIBFT	:=  ./libft/ft_strsub.c \
            ./libft/ft_memdel.c \
            ./libft/ft_putendl_fd.c \
            ./libft/ft_putstr_fd.c \
            ./libft/ft_putendl.c \
           	./libft/ft_strlen.c \
           	./libft/ft_strnew.c \
           	./libft/ft_putchar_fd.c \
           	./libft/ft_memset.c \
           	./libft/ft_bzero.c \
           	./libft/ft_memalloc.c \
           	./libft/ft_putchar.c \
           	./libft/ft_putstr.c \
           	./libft/ft_strncpy.c

OBJ	:=  $(SRC:.c=.o) \
        $(LIBFT:.c=.o)

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror 

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all