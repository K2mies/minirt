# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 15:43:17 by rhvidste          #+#    #+#              #
#    Updated: 2025/07/08 16:50:52 by rhvidste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	miniRT

CC			= 	cc
CFLAGS		= 	-O3 -flto -ffast-math -march=native -Wextra -Werror -Wall 
#CFLAGS		= 	-O3 -flto -march=native -Wextra -Werror -Wall 
#CFLAGS		=  -fno-associative-math -flto -fno-fast-math -Wextra -Werror -Wall 
#CFLAGS		=	-fno-associative-math -fno-fast-math -Wextra -Werror -Wall 

#CFLAGS		= 	-Wextra -Werror -Wall
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
				$(SRC_DIR)/color/minirt_color05.c									\
				$(SRC_DIR)/color/minirt_color06.c									\
				$(SRC_DIR)/color/minirt_color07.c									\
				$(SRC_DIR)/color/minirt_color08.c									\
				$(SRC_DIR)/color/minirt_color09.c									\
				$(SRC_DIR)/color/minirt_color10.c									\
				$(SRC_DIR)/color/minirt_color11.c									\
				\
				$(SRC_DIR)/canvas/minirt_canvas00.c									\
				$(SRC_DIR)/canvas/minirt_canvas01.c									\
				$(SRC_DIR)/canvas/minirt_canvas02.c									\
				\
				$(SRC_DIR)/ppm/minirt_ppm00.c										\
				\
				$(SRC_DIR)/matrix/minirt_matrix00.c									\
				$(SRC_DIR)/matrix/minirt_matrix01.c									\
				$(SRC_DIR)/matrix/minirt_matrix02.c									\
				$(SRC_DIR)/matrix/minirt_matrix03.c									\
				$(SRC_DIR)/matrix/minirt_matrix04.c									\
				$(SRC_DIR)/matrix/minirt_matrix05.c									\
				$(SRC_DIR)/matrix/minirt_matrix06.c									\
				\
				$(SRC_DIR)/transform/minirt_transform00.c							\
				$(SRC_DIR)/transform/minirt_transform01.c							\
				$(SRC_DIR)/transform/minirt_transform02.c							\
				$(SRC_DIR)/transform/minirt_transform03.c							\
				$(SRC_DIR)/transform/minirt_transform04.c							\
				\
				$(SRC_DIR)/ray/minirt_ray00.c										\
				$(SRC_DIR)/ray/minirt_ray01.c										\
				$(SRC_DIR)/ray/minirt_ray02.c										\
				$(SRC_DIR)/ray/minirt_ray03.c										\
				$(SRC_DIR)/ray/minirt_ray04.c										\
				$(SRC_DIR)/ray/minirt_ray05.c										\
				$(SRC_DIR)/ray/minirt_ray06.c										\
				$(SRC_DIR)/ray/minirt_ray07.c										\
				$(SRC_DIR)/ray/minirt_ray08.c										\
				$(SRC_DIR)/ray/minirt_ray09.c										\
				$(SRC_DIR)/ray/minirt_ray10.c										\
				$(SRC_DIR)/ray/minirt_ray11.c										\
				$(SRC_DIR)/ray/minirt_ray12.c										\
				$(SRC_DIR)/ray/minirt_ray13.c										\
				$(SRC_DIR)/ray/minirt_ray14.c										\
				$(SRC_DIR)/ray/minirt_ray15.c										\
				$(SRC_DIR)/ray/minirt_ray16.c										\
				$(SRC_DIR)/ray/minirt_ray17.c										\
				$(SRC_DIR)/ray/minirt_ray18.c										\
				$(SRC_DIR)/ray/minirt_ray19.c										\
				\
				$(SRC_DIR)/object/minirt_object00.c									\
				$(SRC_DIR)/object/minirt_object01.c									\
				$(SRC_DIR)/object/minirt_object02.c									\
				$(SRC_DIR)/object/minirt_object03.c									\
				$(SRC_DIR)/object/minirt_object04.c									\
				$(SRC_DIR)/object/minirt_object05.c									\
				$(SRC_DIR)/object/minirt_object06.c									\
				$(SRC_DIR)/object/minirt_object07.c									\
				$(SRC_DIR)/object/minirt_object08.c									\
				\
				$(SRC_DIR)/mlx/minirt_mlx00.c										\
				\
				$(SRC_DIR)/error/arg_error.c										\
				$(SRC_DIR)/error/error.c											\
				\
				$(SRC_DIR)/parsing/validation.c										\
				$(SRC_DIR)/parsing/sorting.c										\
				$(SRC_DIR)/parsing/utils.c											\
				$(SRC_DIR)/parsing/object.c											\
				$(SRC_DIR)/parsing/validation_utils.c								\
				\
				$(SRC_DIR)/utils/close.c											\
				$(SRC_DIR)/utils/utils.c											\
				$(SRC_DIR)/utils/memory.c											\
				$(SRC_DIR)/utils/quicksort.c										\
				$(SRC_DIR)/utils/containers.c										\
				$(SRC_DIR)/utils/cube.c										\
				$(SRC_DIR)/utils/swap.c										\
				\
				$(SRC_DIR)/remove_this/julesprints.c								\
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
debug:	CFLAGS += $(DEBUG_FLAGS)
debug:	fclean all

libftdebug:
	make debug -C $(LIBFT_DIR)

clean_debug:
	rm -f $(NAME)
	rm -f $(OBJ_DIR)
#-------------------------------------------------------------------------------#
.PHONY: all clean fclean re debug libftdebug clean_debug libmlx bonus
