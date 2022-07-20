# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 05:26:46 by jrasser           #+#    #+#              #
#    Updated: 2022/07/20 21:45:16 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= $(wildcard srcs/*/*.c)
OBJS		:= $(addprefix objs/, $(notdir $(SRCS:.c=.o)))
OS			= ${shell uname}
LIBMLXMAC	= make -C minilibx/
NAME 		= cub3d
CC			= gcc
RM			= @rm -f
CFLAGS		= -Wall -Wextra
CPPFLAGS	= -I./include/ -I./libft/ -I./minilibx/
DEBEUG		= -g -fsanitize=address

objs/%.o: */*/%.c
			@${CC} -o $@ -c $< ${CFLAGS}

ifeq ($(OS),Linux)
LDFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			= -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac
endif

$(NAME): 		$(OBJS)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif

${NAME}	:	${OBJS}
			@$(MAKE) --no-print-directory -C ./libft
			@${CC} -o ${NAME} ${OBJS} -L./libft -lft $(LDFLAGS)

all :		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}
			@make --no-print-directory fclean -C libft/

re : 		fclean all

.PHONY:		all clean fclean re