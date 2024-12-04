# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/12/04 16:21:59 by mkhoury          ###   ########.fr        #
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
		./srcs/init.c							\
		./srcs/terminate.c						\
		./srcs/utils_colors.c					\
		./srcs/debug.c							\
		./srcs/init_cast.c 						\
		./srcs/layer.c							\
		./srcs/time.c							\
		\
		./srcs/parsing/parsing.c				\
		./srcs/parsing/parsing_check_errors.c	\
		./srcs/parsing/parse_asciimap.c			\
		\
		./srcs/pc/procedural_creation.c			\
		./srcs/pc/utils.c						\
		./srcs/pc/algo.c						\
		./srcs/pc/algo_delegate.c				\
		\
		./srcs/rendering/draw_line.c			\
		./srcs/rendering/show_fps.c				\
		./srcs/rendering/minimap.c				\
		./srcs/rendering/draw_square.c 			\
		./srcs/rendering/draw_orientation.c 	\
		\
		./srcs/raycasting/raycast.c				\
		./srcs/raycasting/calcul_raycast.c 		\
		./srcs/raycasting/draw_cast.c 			\
		./srcs/raycasting/draw_rectangle.c		\
		./srcs/raycasting/entity.c 				\
		\
		./srcs/network/init.c					\
		./srcs/network/menu.c					\
		./srcs/network/mutual_addr.c			\
		./srcs/network/send.c					\
		\
		./srcs/movements/movement.c				\
		\
		./main.c\
		./srcs/deg2rad.c

LMAKE = @make --no-print-directory -C

OBJS_DIR = objs

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.obj)

DEPS = $(OBJS:%.obj=%.d)

INCLUDES = -I ./includes/ -I $(LIBFT_P)/ -I .

CFLAGS = -Wall -Wextra -MMD -Ofast -g3 -fPIE #-Werror

LIBFT_P = ./libft

LIB = $(LIBFT_P)/libft.a \

EXTERN_LIB = -L./MLX42-2.4.1/build -ldl -lm -lmlx42 -lglfw -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi

# ############## #
#*    REGLES    *#
# ############## #

all: libft_comp   $(NAME) mischief

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
