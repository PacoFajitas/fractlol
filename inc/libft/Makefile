# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 21:15:02 by tfiguero          #+#    #+#              #
#    Updated: 2023/05/22 18:33:12 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER	=	libft.h

NAME	=	libft.a

SRCS	=	ft_atoi.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c	\
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c 

BONUS_S = 	ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

BONUS_O	= 	$(BONUS_S:.c=.o)

OBJS	= 	$(SRCS:.c=.o)

CC	= 	cc

RM	= 	rm -f

LIBC	= 	ar -rcs

FLAGS	= 	-Wall -Wextra -Werror

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):: ${OBJS} ${HEADER}
	$(LIBC) $(NAME) $(OBJS)

$(NAME):: 
	@echo "Hello, Libft already compiled 🥶"

all: $(NAME)

bonus: .bonus

.bonus:	$(NAME) $(BONUS_O) $(HEADER)
	$(LIBC) $(NAME) $(BONUS_O)
	touch .bonus

fclean: clean
	$(RM) $(NAME) .bonus

clean:
	$(RM) $(OBJS) $(BONUS_O)

re: fclean all

.PHONY: all clean fclean re .c.o