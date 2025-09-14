# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 05:55:59 by joaolive          #+#    #+#              #
#    Updated: 2025/09/14 09:16:26 by joaolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Colors
CC_PINK = \033[38;2;255;121;198m
CC_BLUE = \033[38;2;139;233;253m
CC_YELLOW = \033[38;2;241;250;140m
RESET = \033[0m

# Tools
CC = cc
AR = ar rcs
RM = rm -rf

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = deps/libft
MLX_DIR = deps/mlx
MLX_BUILD  = $(MLX_DIR)/build

# Flags and Includes
CCFLAGS = -Wall -Wextra -Werror -g
DEPFLAGS = -MMD -MP
CPPFLAGS = -Iinclude -I$(LIBFT_DIR)/include -I$(MLX_DIR)/include

# Libft and MLX
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_BUILD)
LDLIBS = -lft -lmlx42 -lglfw -lpng16 -ldl -pthread -lm

SRC_NAMES = $(addsuffix .c, \
			ft_initializr_map \
			ft_parse_map \
			ft_read_map \
			ft_validate_suffix \
			ft_validate_map \
			ft_check_dimension \
			ft_check_flags \
			ft_check_roads \
			ft_check_walls \
			ft_flood_fill \
			ft_clean_up \
			ft_fill_grid \
			ft_count_rows \
			ft_load_image \
			ft_load_all_images \
			ft_render \
			ft_cleanup_assets \
			ft_terminate \
			ft_initializr_game \
			ft_hook_handler \
			ft_player_mv_hook \
			ft_disable_collectible \
			ft_print_error \
			ft_close_window_hook \
			main)

# Source files
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))

# Object files
SRC_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Dependencies
DEPS = $(SRC_OBJS:.o=.d)

all:
	@echo ""
	@echo "░██████╗░█████╗░░░░░░░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "██╔════╝██╔══██╗░░░░░░██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "╚█████╗░██║░░██║░░░░░░██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "░╚═══██╗██║░░██║░░░░░░██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "██████╔╝╚█████╔╝█████╗███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "╚═════╝░░╚════╝░╚════╝╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"
	@echo ""
	@$(MAKE) build

build: $(NAME)
	@echo ""
	@echo "───────────────────────────────────────────────────"
	@echo " 🎯 $(NAME) is up to date! Nothing to rebuild 🚀"
	@echo "───────────────────────────────────────────────────"
	@echo ""

$(NAME): $(MLX_BUILD)/libmlx42.a $(SRC_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(SRC_OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)
	@echo "🎉 $(NAME) compiled successfully! 🎊"

# Include dependency files to track header changes
-include $(DEPS)

$(MLX_BUILD)/libmlx42.a:
	@mkdir -p $(MLX_BUILD)
	@cd $(MLX_BUILD) && cmake .. >/dev/null
	@cmake --build $(MLX_BUILD) -j4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "  $(CC_BLUE)[CC]$(RESET) $(CC_YELLOW)Compiling$(RESET) $(CC_PINK)SO_LONG$(RESET) $(CC_YELLOW)module$(RESET) $(CC_BLUE)%-28s$(RESET) -> $(CC_PINK)%s$(RESET)\n" $< $@
	@$(CC) $(CCFLAGS) $(DEPFLAGS) $(CPPFLAGS) -c $< -o $@

# Cleaning Rules
clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C $(LIBFT_DIR)
	@echo "🧼 Object files cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(LIBFT_DIR)
	@$(RM) $(MLX_BUILD)
	@echo "🧹 Full clean complete! Library removed."

re: fclean all
	@echo "🚀 Project has been rebuilt from scratch!"

# PHONY Targets
.PHONY: all clean fclean re build
