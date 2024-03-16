# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmorello <pmorello@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:20:58 by pmorello          #+#    #+#              #
#    Updated: 2024/03/14 11:59:44 by pmorello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

ARXIUS = ft_printf.c ft_hexas.c ft_numbers.c ft_text.c

OBJS = ${ARXIUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
		${AR} ${NAME} ${OBJS}
	
.c.o:	 
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
		${RM} ${OBJS}

fclean: clean 
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re



