# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 05:26:46 by jrasser           #+#    #+#              #
#    Updated: 2022/07/20 21:02:23 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= $(wildcard srcs/*/*.c)
OBJS		:= $(addprefix objs/, $(notdir $(SRCS:.c=.o)))
RM			= @rm -f
NAME 		= cub3d
CC			= gcc
CFLAGS		= -Wall -Wextra
LDFLAGS		= -I./include/ -I./libft/ -I/Users/ydumaine/.brew/opt/readline/include -I./minilibx/
DEBEUG		= -g -fsanitize=address
MINILIBX	= -L./minilibx -lmlx -framework OpenGL -framework AppKit -lz

objs/%.o: */*/%.c
			@${CC} -o $@ -c $< ${CFLAGS} ${DEBEUG} 

${NAME}	:	${OBJS}
			@$(MAKE) --no-print-directory -C ./libft
			@${CC} -o ${NAME} ${OBJS} ${DEBEUG} -L./libft -lft ${MINILIBX}

all :		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}
			@make --no-print-directory fclean -C libft/

re : 		fclean all

.PHONY:		all clean fclean re
