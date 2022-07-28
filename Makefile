# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 05:26:46 by jrasser           #+#    #+#              #
#    Updated: 2022/07/29 01:18:45 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS 		= $(wildcard srcs/*/*.c)
SRCS_BONUS	= $(wildcard srcs_bonus/*/*.c)
OBJS		:= $(addprefix objs/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS	:= $(addprefix objs/, $(notdir $(SRCS_BONUS:.c=.o)))
OS			= ${shell uname}
#LIBMLXMAC	= @make --no-print-directory -C minilibx/
NAME 		= cub3D
NAME_BONUS	= cub3D_bonus
CC			= gcc
RM			= @rm -f
CFLAGS		= -Wall -Wextra
CPPFLAGS	= -I./include/ -I./libft/
DEBEUG		= -g -fsanitize=address
TOTEM 		= 🦜

objs/%.o: srcs/*/%.c
			@${CC} -o $@ -c $< ${CFLAGS} ${DEBEUG}
			@printf	"\033[2K\r${BLU}${TOTEM} [BUILD]${RST}	'$<' $(END)"

objs/%.o: srcs_bonus/*/%.c
			@${CC} -o $@ -c $< ${CFLAGS} ${DEBEUG}
			@printf	"\033[2K\r${BLU}${TOTEM} [BUILD]${RST}	'$<' $(END)"

ifeq ($(OS),Linux)
LDFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			= -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac -I./minilibx/
endif




$(NAME): 	$(OBJS)
			@printf "\033[2K\r\033[0;32m${TOTEM} [END]\033[0m	$(NAME)$(END)\n"
ifeq ($(OS),Darwin)
			$(LIBMLXMAC)
endif
			@$(MAKE) --no-print-directory -C ./libft
			@${CC} -o ${NAME} ${OBJS} -L./libft -lft $(LDFLAGS) ${DEBEUG}




$(NAME_BONUS): 	$(OBJS_BONUS)
				@printf "\033[2K\r\033[0;32m${TOTEM} [END]\033[0m	$(NAME_BONUS)$(END)\n"
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
				@$(MAKE) --no-print-directory -C ./libft
				@${CC} -o ${NAME_BONUS} ${OBJS_BONUS} -L./libft -lft $(LDFLAGS) ${DEBEUG}





all :		${NAME}
bonus :		${NAME_BONUS}
clean :
			${RM} ${OBJS} ${OBJS_BONUS}
			@printf "\033[2K\r${GRN}${TOTEM} [CLEAN]${RST}	done$(END)\n"

fclean :	clean
			${RM} ${NAME} ${NAME_BONUS}
			@make --no-print-directory fclean -C libft/
			@printf "\033[2K\r${GRN}${TOTEM} [FCLEAN]${RST}	done$(END)\n"

re : 		fclean all
reb :		fclean bonus
.PHONY:		all clean fclean re bonus reb
