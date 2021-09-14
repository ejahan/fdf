# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 17:27:03 by ejahan            #+#    #+#              #
#    Updated: 2021/09/14 21:00:27 by ejahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	./SRCS/fdf.c ./SRCS/parsing.c ./SRCS/parsing2.c ./SRCS/utils.c \
			./SRCS/calculs.c ./SRCS/calculs2.c 

SRCS_BONUS	=	./SRCS/fdf.c ./SRCS/parsing.c ./SRCS/parsing2.c ./SRCS/utils.c \
			./SRCS/calculs_bonus.c ./SRCS/calculs2_bonus.c

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra #-g3 -fsanitize=address

MLX_FLAG	=	-L./mlx_linux -lbsd -lmlx -lXext -lX11 -lm

NAME		=	fdf

RM			=	rm -rf

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			make -C libft/
			make -C mlx_linux/
			${CC} -o ${NAME} ${OBJS} ${CFLAGS} ${MLX_FLAG} libft/libft.a

clean:
			make -C libft/ -f Makefile clean
			make -C mlx_linux/ -f Makefile clean
			${RM} ${OBJS}
			${RM} ${OBJS_BONUS}

fclean:		clean
			make -C libft/ -f Makefile fclean
			${RM} ${NAME}

bonus:		${OBJS_BONUS}
			make -C libft/
			make -C mlx_linux/
			${CC} -o ${NAME} ${OBJS_BONUS} ${CFLAGS} ${MLX_FLAG} libft/libft.a

re:			fclean all
