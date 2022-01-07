# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 20:05:23 by fchrysta          #+#    #+#              #
#    Updated: 2021/12/13 21:04:05 by fchrysta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		ft_printf.c ft_print_variables_number.c \
				ft_print_variables_char.c ft_printf_helpers.c

HEADER =		ft_printf.h

CC		=		gcc

NAME =			libftprintf.a

OBJECTS	=		$(SOURCES:.c=.o)

FLAGS =			-Wall -Wextra -Werror

.PHONY: all re clean fclean

all	:			$(SOURCES) $(NAME)


$(NAME)	:		$(OBJECTS)
					ar -rc $(NAME) $^

%.o :			%.c $(HEADER)
				$(CC) $(FLAGS) $< -c

clean :
					rm -rf $(OBJECTS)

fclean :		clean
					rm -rf $(NAME)

re:				fclean all
