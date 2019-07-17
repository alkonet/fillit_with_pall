# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloggins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 15:59:04 by gloggins          #+#    #+#              #
#    Updated: 2019/04/10 15:07:48 by gloggins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libft.a

FLAG=	-Wall -Wextra -Werror

SRCS=	ft_memcmp.c ft_putendl_fd.c ft_strcpy.c ft_strstr.c ft_striteri.c \
		ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_tolower.c \
		ft_atoi.c ft_isdigit.c ft_memmove.c ft_putstr.c ft_strlen.c ft_toupper.c \
		ft_bzero.c ft_memset.c ft_putstr_fd.c ft_strncat.c ft_strjoin.c \
		ft_isalnum.c ft_isprint.c ft_putchar.c ft_strcat.c ft_strncmp.c \
		ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_strncpy.c ft_putnbr.c \
		ft_isalpha.c ft_memchr.c ft_putendl.c ft_strcmp.c ft_strnstr.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_strnequ.c ft_strmap.c ft_strmapi.c ft_lstadd.c \
		ft_strequ.c ft_strsub.c ft_strlcat.c ft_strrchr.c ft_lstiter.c \
		ft_strtrim.c ft_strdup.c ft_del_white.c ft_itoa.c ft_strsplit.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstmap.c ft_pos_neg.c \
		ft_strndup.c ft_foreach.c ft_count_if.c

OBJECTS= $(SRCS:.c=.o)

INCLUDE=./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc $(FLAG) -I$(INCLUDE) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
