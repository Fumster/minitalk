# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 20:05:23 by fchrysta          #+#    #+#              #
#    Updated: 2022/01/11 20:53:45 by fchrysta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_SRV =	server.c 
SOURCES_CLT =	client.c
HEADER =		minitalk.h
CC		=		gcc
NAME_SRV =		server
NAME_CLT =		client
LIB =			./ft_printf/libftprintf.a
OBJECTS_SRV	=	$(SOURCES_SRV:.c=.o)
OBJECTS_CLT	=	$(SOURCES_CLT:.c=.o)
FLAGS =			-Wall -Wextra -Werror
INCLUDES =		-L./ft_printf -lftprintf

.PHONY: all re clean fclean

all	:			lib $(NAME_SRV) $(NAME_CLT)


lib :
				@make -C ft_printf

$(NAME_SRV)	:	$(OBJECTS_SRV) $(LIB)
				$(CC) $(OBJECTS_SRV) $(INCLUDES) -o $@

$(NAME_CLT) :	$(OBJECTS_CLT)
				$(CC) $(OBJECTS_CLT) -o $@

%.o : 			%.c $(HEADER)
				$(CC) $(FLAGS) $< -c

clean :
				rm -rf $(OBJECTS_SRV) $(OBJECTS_CLT)
				@make clean -C ft_printf

fclean :		clean
				rm -rf $(NAME_SRV) $(NAME_CLT)
				@make fclean -C ft_printf

re:				fclean all
