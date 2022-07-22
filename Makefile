# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 05:26:46 by jrasser           #+#    #+#              #
#    Updated: 2022/07/21 20:13:40 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= $(wildcard mandatory/srcs/*/*.c)
SRCS_BONUS	= $(wildcard bonus/srcs/*/*.c)
OBJS		:= $(addprefix mandatory/objs/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS	:= $(addprefix bonus/objs/, $(notdir $(SRCS_BONUS:.c=.o)))
OS			= ${shell uname}
LIBMLXMAC	= make -C minilibx/
NAME 		= cub3D
NAME_BONUS	= cub3D_bonus
CC			= gcc
RM			= @rm -f
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I./include/ -I./libft/
DEBEUG		= -g -fsanitize=address

mandatory/objs/%.o: mandatory/*/*/%.c
			@${CC} -o $@ -c $< ${CFLAGS} ${DEBEUG}

bonus/objs/%.o: bonus/*/*/%.c
			@${CC} -o $@ -c $< ${CFLAGS} ${DEBEUG} 

ifeq ($(OS),Linux)
LDFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			= -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac -I./minilibx/
endif

$(NAME): 	$(OBJS)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
			@$(MAKE) --no-print-directory -C ./libft
			@${CC} -o ${NAME} ${OBJS} -L./libft -lft $(LDFLAGS) ${DEBEUG} 

$(NAME_BONUS): 	$(OBJS_BONUS)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
			@$(MAKE) --no-print-directory -C ./libft
			@${CC} -o ${NAME_BONUS} ${OBJS_BONUS} -L./libft -lft $(LDFLAGS) ${DEBEUG} 


all :		${NAME}
bonus :		${NAME_BONUS}
clean :
			${RM} ${OBJS}

clean_bonus :
			${RM} ${OBJS_BONUS}

fclean :	clean
			${RM} ${NAME}
			@make --no-print-directory fclean -C libft/

fclean_bonus :	clean_bonus
				${RM} ${NAME_BONUS}
				@make --no-print-directory fclean -C libft/

re : 		fclean all
re_bonus :	fclean_bonus bonus
.PHONY:		all clean fclean re bonus clean_bonus fclean_bonus re_bonus
