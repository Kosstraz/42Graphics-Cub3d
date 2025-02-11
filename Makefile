# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2025/02/11 17:19:24 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################ #
#*    COULEURS    *#
# ################ #

CLASSIC	= \e[0m
WHITE	= \e[38;2;238;232;213m
BOLD	= \e[1m
# BLACK	= \e[38;2;0;0;0m
BLACK	= \e[30m
RED   	= \e[31m
GREEN  	= \e[32m
BLUE 	= \e[38;2;0;36;148m
PURPLE 	= \e[38;2;211;54;130m
CYAN   	= \e[36m
YELLOW 	= \e[38;2;250;189;0m

# ############### #
#*   VARIABLES   *#
# ############### #

NAME = cub3D

CC = @cc

SRCS =	./srcs/cub3d.c							\
		./srcs/hooks.c							\
		./srcs/hook_resize.c					\
		./srcs/key_handling.c					\
		./srcs/key_handling2.c					\
		./srcs/init.c							\
		./srcs/init2.c							\
		./srcs/terminate.c						\
		./srcs/utils_colors.c					\
		./srcs/utils_colors2.c					\
		./srcs/debug.c							\
		./srcs/init_cast.c 						\
		./srcs/layer.c							\
		./srcs/time.c							\
		\
		./srcs/doors/doors.c					\
		./srcs/doors/doors_extra.c				\
		\
		./srcs/audio/audio.c					\
		./srcs/audio/audio_utils.c				\
		\
		./srcs/parsing/utils.c					\
		./srcs/parsing/parsing.c				\
		./srcs/parsing/parsing2.c				\
		./srcs/parsing/parsing_check_errors.c	\
		./srcs/parsing/parse_asciimap.c			\
		./srcs/parsing/parse_asciimap2.c		\
		\
		./srcs/rendering/draw_line.c			\
		./srcs/rendering/show_fps.c				\
		./srcs/rendering/minimap.c				\
		./srcs/rendering/draw_square.c 			\
		./srcs/rendering/draw_orientation.c 	\
		\
		./srcs/raycasting/raycast.c				\
		./srcs/raycasting/raycast_extra.c		\
		./srcs/raycasting/calcul_raycast.c 		\
		./srcs/raycasting/draw_cast.c 			\
		./srcs/raycasting/draw_cast_extra.c 	\
		./srcs/raycasting/draw_rectangle.c		\
		./srcs/raycasting/entity.c 				\
		./srcs/raycasting/entity_extra.c		\
		./srcs/raycasting/entity_extra2.c		\
		\
		./srcs/network/init.c					\
		./srcs/network/ft_net.c					\
		./srcs/network/menu.c					\
		./srcs/network/mutual_addr.c			\
		./srcs/network/send.c					\
		./srcs/network/send2.c					\
		./srcs/network/send_textures.c			\
		\
		./srcs/movements/movement.c				\
		./srcs/movements/movement2.c			\
		./srcs/movements/bubbles.c				\
		\
		./main.c								\
		./srcs/deg2rad.c

LMAKE = @make --no-print-directory -C

OBJS_DIR = objs

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.obj)

DEPS = $(OBJS:%.obj=%.d)

INCLUDES = -I ./includes/ -I $(LIBFT_P)/ -I .

OPTIFLAGS =	-Ofast -march=native -mtune=generic -funroll-loops -fomit-frame-pointer -ffast-math

CFLAGS = -Wall -Wextra -Wshadow -Wuninitialized -Winit-self -MMD $(OPTIFLAGS) -fPIE -g3 #-Werror

LIBFT_P = ./libft

LIB = $(LIBFT_P)/libft.a \

EXTERN_LIB = -L./MLX42-2.4.1/build -ldl -lm -lmlx42 -lglfw -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lSDL2

# ############## #
#*    REGLES    *#
# ############## #

all: libft_comp   $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(EXTERN_LIB) -o $@
	@echo "$(BOLD)$(CYAN)Exécutable $(NAME) créé avec succès!$(CLASSIC)"

$(OBJS_DIR)/%.obj: %.c
	@mkdir -p $(@D)
	@echo "$(GREEN)🗸 Compilation $(BOLD)$(YELLOW)$<$(CLASSIC)"
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BOLD)$(RED)"
	rm $(LIBFT_P)/$(OBJS_DIR) -rf
	rm $(OBJS_DIR) -rf
	@echo "$(CLASSIC)"

fclean: clean
	@echo "$(BOLD)$(RED)"
	rm $(LIB) -f
	rm $(NAME) -f
	@echo "$(BOLD)$(GREEN)Tout a été supprimé... 🗑️\n$(CLASSIC)"

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)

# ############## #
#*    AUTRES    *#
# ############## #

# Permet de compiler la libft avant $(NAME)
libft_comp:
	$(LMAKE) $(LIBFT_P)

mischief:
	@echo "$(WHITE)$(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$(YELLOW)%(/(############(/(%$(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@$(YELLOW)((############################(($(BLACK)@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@$(YELLOW)/########%%%%%%%%%%%%%%%%%%%%##########/$(BLACK)@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@@@@$(YELLOW)/######%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#######/&$(BLACK)@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@$(YELLOW)######%#%&@@@@@@@@@@&%%%%%%%%%%%%%%%%%%%%%%%%######($(BLACK)@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@$(YELLOW)(####%@@@@@@@@@@@&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%%%######/$(BLACK)@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@$(YELLOW)%####@@@@@@@@@@@&&&&&&&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%%#######$(BLACK)@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@$(YELLOW)/##%@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%###%%/$(BLACK)@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@$(YELLOW)(##&@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%%%%%%%%%%%##%%%($(BLACK)@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@$(YELLOW)(%%&@@@@@&&&&&&&&&&&&&&&&&&&&&.*,*,,&&&&&&&%%%%%%%%%%%%%%%%%%%%%%($(BLACK)@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@$(YELLOW)(##&@@&&&&&&&&&&&&&&&&&&&&&&&&.,.(%%#.&&&%#####%%%%%%%%%%%%%%%%%%&#/$(BLACK)@@"
	@sleep 0.01
	@echo "@@@@@@@@@$(YELLOW)&##%&&&&&&&&&&&&&&&&&&&&&&&&&&.,....,%%&%%####&&&&&%%%%%%%%%%%%%%%&&#$(BLACK)@@"
	@sleep 0.01
	@echo "@@@@@@@@@$(YELLOW)###&&&&&&&&&&&&&&&&&&&&&&&&&%,,,$(WHITE)#&@&&&&$(YELLOW).###%&&&%(/(((%%%%%%%%%%%%%&&#/$(BLACK)@"
	@sleep 0.01
	@echo "@@@@@@@@@$(YELLOW)(#%&&&&&&&&&&&&&&&&&&&&&&&&(,,*.*** $(WHITE)@@@$(YELLOW)&#(%%%%(/%%%%%%%%%%%%%%%%%%&&#/$(BLACK)@"
	@sleep 0.01
	@echo "@@@@@@@@@$(YELLOW)(#%&&&&&&&&&&&&&&&&&&/#&&&,,,,,$(BLUE)@*  *$(WHITE),@@@$(YELLOW)&*#%%/%%/%%%%%%%%%%%%%%%%%&&#/$(BLACK)@"
	@sleep 0.01
	@echo "@@@@@@@@@$(YELLOW)###,..*%&&&&&&&&&(.&&&.(&.,,,* $(BLUE)(   #$(WHITE).@@@$(YELLOW)&((%%%%%(%%%%%%%%%%%%%%%%%&&#($(BLACK)@"
	@sleep 0.01
	@echo "@@@@@@@@@@$(YELLOW)(#,..,,,,,, #&&&&,.&&&.,,,,($(WHITE)%@@$(YELLOW), ,$(WHITE)@@@@@$(YELLOW)&,#%%%%%/&#%%%%%%%%%%%%%%%&%($(BLACK)@@"
	@sleep 0.01
	@echo "@@@@@@@@@@$(YELLOW)##.&&&#,$(WHITE)%%/$(YELLOW)..,,,,.,.&%%.,,%.$(WHITE)@@@@@@@@@@$(YELLOW)&,##%%%%#%&#%%%%%%%%%%%%%%%&#($(BLACK)@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@$(YELLOW)/#&&%(#&$(WHITE)@@ $(BLUE)/  %$(YELLOW)*/*#%%%%%%%%#.$(WHITE)&&&&&&&$(YELLOW)*(#%%%%%##$(WHITE)&&$(YELLOW)@#%%%%%%%%%%%%%%%/$(BLACK)@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@$(YELLOW)/%%###,$(WHITE)@@@@@@@@&$(YELLOW)/%%%%%%%%%%%########%%%%%%(&$(WHITE)@@@@$(YELLOW)#%%%%%%%%%%%%%%/$(BLACK)@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@$(YELLOW)##%%%##**$(WHITE)%&&$(YELLOW)(,#%%%%%%%%%%%%%%%%%%%######/$(WHITE)@#@@@$(YELLOW)(&%%%%%%%%%##%#($(BLACK)@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@$(YELLOW)/#%%%%%%%%%%%%%%%%%%%%%%%%%%########/$(WHITE)@@@@(@@$(YELLOW)%%%%%%%%%%###/$(BLACK)@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@$(YELLOW)/#%%%%%%%%(#&&%#(%%#############/$(WHITE)@@@@@@@($(YELLOW)%%%%%%%%%###(&$(BLACK)@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@@$(YELLOW)/##%%%%#%&&%%%#(#%#######%#/$(WHITE)(@@@@@@@&($(YELLOW)&%%%%%%%###/$(BLACK)@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@$(YELLOW)((#(/#/##(/%%%%%%####((###(#$(WHITE)@@@@#@@@@/$(YELLOW)&&%##%%%###/&$(BLACK)@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@$(YELLOW)%%%%###%%%%%%(%%%%%%%@@@@%$(WHITE)((%&&%###$(YELLOW)%#%##/#\/#\\#$(BLACK)@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@$(YELLOW)(%&&%%%%%%%%%%##%%%%%%%%%&&&/%#%#(#%#%####/%$(BLACK)@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@@@@@$(YELLOW)(%%%%(%&&&&&%%%%%%%&&%////(##&$(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@@@@$(YELLOW)(%%%/&&&&&&&&&&&%%%%%%&%#$(BLACK)@@@@@#$(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@@@$(YELLOW)%(%%##&&&%&&&&&&&&&%%%%%%%($(BLACK)@@@@@@#$(BLACK)@@@&@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@$(YELLOW)/%%%%##&&&&%&&&&&%&&&&%%%%%%/$(BLACK)@@@@@@#$(BLACK)@@@@($(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@$(YELLOW)(&&&%%%/&&&&%%%&##&&&&&%%#(%#($(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@%@@@$(YELLOW)/&&%%%%/&&&%%%%/&&&%%%(#%%/&$(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@(@@@(@@@@$(YELLOW)/%%%%#/%%%%#(&&%%%%/%#($(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@/@@@@(@@@$(YELLOW)/##%%%%%(%&&%%%%###($(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@#@$(YELLOW)%/%&&&#/%/%%#%/(&$(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@sleep 0.01
	@echo "@@@@@@@@@@@@@@@$(YELLOW)&/##(($(BLACK)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n$(CLASSIC)"
