# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 01:41:07 by tfiguero          #+#    #+#              #
#    Updated: 2023/10/05 23:31:56 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -O2 -g -fsanitize=address
MN_LIB = ./miniLibX/
FRAME = -framework OpenGL -framework AppKit


SRC = fract_ol.c render.c
L_SRC = ./src
L_ML = ./miniLibX/libmlx.a
INC =	-I ./inc/\
		-I ./miniLibX/\

D_OBJ = $(L_SRC)/obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

all: dir $(NAME)

-include $(DEP)

dir:
	@make -C $(MN_LIB) 
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(L_SRC)/%.c
	$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)

$(NAME):: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(L_ML) $(FRAME) -o $(NAME) $(INC)

$(NAME) ::
	@echo "Hello, $(NAME) already compiled 🌚"
	
.PHONY: clean fclean re

fclean: clean
	$(RM) $(NAME) $(NAME)

clean:
	$(RM) $(D_OBJ)
	@make clean -C $(MN_LIB) --no-print-directory

re: fclean all
.SILENT: