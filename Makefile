# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 05:26:46 by jrasser           #+#    #+#              #
#    Updated: 2022/07/19 17:55:27 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/main.c\
			srcs/parsing.c\
			srcs/parsing_utils.c\
			srcs/parsing_map.c\
			srcs/rendering.c\
			srcs/texture_wallcasting.c\
			srcs/mini_map.c\
			srcs/wallcasting.c\
			srcs/wallcasting_part_2.c\
			srcs/movements_keyboard.c\
			srcs/movements_mouse.c\
			srcs/event.c\
			srcs/hook.c\
			srcs/floorcasting.c\
			srcs/init.c\
			srcs/init_texture.c\
			srcs/sprite_casting.c\

OBJS 		= ${SRCS:.c=.o}
RM			= @rm -f
NAME 		= cub3d
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -I./include/ -I./libft/ -I/Users/ydumaine/.brew/opt/readline/include -I./minilibx/
DEBEUG		= -fsanitize=address
MINILIBX	= -L./minilibx -lmlx  -framework OpenGL -framework AppKit -lz

.c.o:		
			@${CC} -g ${CFLAGS} -c ${LDFLAGS} $< -o ${<:.c=.o}

${NAME}	:	${OBJS}
			@$(MAKE) --no-print-directory -C ./libft
			@gcc -o ${NAME} ${OBJS} -g ${DEBEUG} -lreadline  -L/Users/ydumaine/.brew/opt/readline/lib -L./libft -lft ${MINILIBX}

all :		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}
			@make --no-print-directory fclean -C libft/

re : 		fclean all

.PHONY:		all clean fclean re
