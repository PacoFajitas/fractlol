NAME = fractol

#########
RM = rm -f
CC = cc
CFLAGS = -Werror -Wextra -Wall #-g -fsanitize=address
#########

#########
FILES = args_check fract_ol hooks mlx_func render

SRC = $(addsuffix .c, $(FILES))

vpath %.c srcs
#########

#########
OBJ_DIR = objs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ))) 
#########

########
MLX_DIR = inc/mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
########

########
LIBFT_DIR = inc/libft
LIBFT = inc/libft/libft.a
########


#########
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@${CC} $(CFLAGS) -Imlx -MMD -c $< -o $@

all:
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -g -fsanitize=address -o $(NAME)
	@echo "EVERYTHING DONE  "

clean:
	$(MAKE) clean -C $(MLX_DIR) --no-print-directory
	$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(OBJ) $(DEP) --no-print-directory
	$(RM) -r $(OBJ_DIR) --no-print-directory
	@echo "OBJECTS REMOVED   "

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(NAME) --no-print-directory
	@echo "EVERYTHING REMOVED   "

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)

#########
