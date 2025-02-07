# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 11:40:43 by dalara-s          #+#    #+#              #
#    Updated: 2024/10/02 17:48:12 by dalara-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS := $(shell find ./src -iname "*.c")

BONUS_SRCS := $(shell find ./src_bonus -iname "*.c")
				
OBJS= ${SRCS:.c=.o}

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJS}
			ar -rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	/bin/rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all

.PHONY: re fclean clean bonus all .c.o
