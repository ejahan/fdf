# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 13:02:24 by elisa             #+#    #+#              #
#    Updated: 2021/08/07 15:36:18 by ejahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

INCS	=	includes

SRCS	=	ft_strrchr.c ft_isalnum.c ft_substr.c \
		ft_memchr.c ft_strlcat.c ft_strjoin.c \
		ft_tolower.c ft_isalpha.c ft_strtrim.c \
		ft_isdigit.c ft_memmove.c ft_split.c \
		ft_memccpy.c ft_strchr.c ft_itoa.c \
		ft_strlcpy.c ft_memcmp.c ft_strmapi.c \
		ft_toupper.c ft_memcpy.c ft_putchar_fd.c \
		ft_isascii.c ft_strlen.c ft_putstr_fd.c \
		ft_isprint.c ft_memset.c ft_putendl_fd.c \
		ft_strnstr.c ft_bzero.c ft_putnbr_fd.c \
		ft_strncmp.c ft_atoi.c ft_calloc.c \
		ft_strdup.c ft_strcpy.c gnl.c \

OBJS	=	${SRCS:.c=.o}

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	ar rc

LIBR	=	ranlib

RM	=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
