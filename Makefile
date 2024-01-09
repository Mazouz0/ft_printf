# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:31:47 by mohmazou          #+#    #+#              #
#    Updated: 2023/12/09 23:53:44 by mohmazou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = \
		ft_printf.c ft_putchars.c ft_put_hexa.c ft_putnbrs.c

OBJECTS	= $(SOURCES:.c=.o)

CC = cc

AR = ar -rcs

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c ft_printf.h
	$(CC) -c $(CFLAGS) $<

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
