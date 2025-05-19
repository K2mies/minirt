# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 13:18:47 by rhvidste          #+#    #+#              #
#    Updated: 2025/05/13 17:05:09 by rhvidste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	miniRT

CC			= 	cc
CFLAGS		= 	-Wextra -Werror -Wall
DEBUG_FLAGS	=	-g
#-----------------------------------------------------------------------------------#
LIBLMX_DIR	=	./lib/MLX42
#-----------------------------------------------------------------------------------#
LIBFT_DIR	=	./lib/libft
LIBFT		=	$(LIBFT_DIR)/libft.a
#-----------------------------------------------------------------------------------#
INC_DIR		=	./include
INC_FLAGS	=	-I $(LIBFT_DIR) -I $(INC_DIR) -I $(LIBLMX_DIR)/include
#-----------------------------------------------------------------------------------#
HEADER		=	$(INC_DIR)/minirt.h
#LIBS		= 	$(LIBLMX_DIR)/build/libmlx42.a -L/opt/homebrew/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -ldl -pthread -lm
LIBS		= 	$(LIBLMX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
#-----------------------------------------------------------------------------------#
SRC_DIR		=	./src
OBJ_DIR		=	./obj

#-----------------------------------------------------------------------------------#
SRC		=		$(SRC_DIR)/minirt_main.c											\
				\
				$(SRC_DIR)/tuple/minirt_tuples00.c									\
				$(SRC_DIR)/tuple/minirt_tuples01.c									\
				$(SRC_DIR)/tuple/minirt_tuples02.c									\
				$(SRC_DIR)/tuple/minirt_tuples03.c									\
				$(SRC_DIR)/tuple/minirt_tuples04.c									\
				$(SRC_DIR)/tuple/minirt_tuples05.c									\
				$(SRC_DIR)/tuple/minirt_floats.c									\
				\
				$(SRC_DIR)/color/minirt_color00.c									\
				$(SRC_DIR)/color/minirt_color01.c									\
				$(SRC_DIR)/color/minirt_color02.c									\
				$(SRC_DIR)/color/minirt_color03.c									\
				$(SRC_DIR)/color/minirt_color04.c									\
				\
				$(SRC_DIR)/canvas/minirt_canvas00.c									\
				$(SRC_DIR)/canvas/minirt_canvas01.c									\
				\
				$(SRC_DIR)/ppm/minirt_ppm00.c										\


#-----------------------------------------------------------------------------------#
OBJ 		= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
#-----------------------------------------------------------------------------------#
#INC			=	include/
#SRC_DIR		=	src/
#OBJ_DIR		=	obj/
#-----------------------------------------------------------------------------------#
all: $(LIBLMX_DIR) libmlx $(LIBFT) $(NAME)

libmlx:
		@cmake $(LIBLMX_DIR) -B $(LIBLMX_DIR)/build && make -C $(LIBLMX_DIR)/build -j4

$(LIBLMX_DIR):
		@git clone https://github.com/codam-coding-college/MLX42.git $(LIBLMX_DIR)
		@echo "$(CYAN)cloned MLX library$(DEF_COLOR)"

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) $(OBJ) $(INC_FLAGS) $(LIBS) $< $(LIBFT) -o $@
#		@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LIBFT) $(HEADER) -o $(NAME)
		@echo "$(GREEN)Succesfully built miniRT!$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(LIBFT):
		make -C ./lib/libft
#$(OBJ_DIR):
#		@mkdir -p $@
#-----------------------------------------------------------------------------------#
clean:
		@rm -rf $(OBJ_DIR)
		@rm -rf $(BOBJ_DIR)
		@make clean -C ./lib/libft
		@make clean -C ./lib/MLX42/build

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(BNAME)
		@rm -rf $(LIBFT)
		@rm -rf $(LIBLMX_DIR)
		@echo "$(CYAN)miniRT executable files cleaned!$(DEF_COLOR)"
		@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"
		@echo "$(CYAN)mlx executable files cleaned!$(DEF_COLOR)"

re: fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything for miniRT!$(DEF_COLOR)"
#-------------------------------------------------------------------------------#
.PHONY: all clean fclean re libmlx bonus
