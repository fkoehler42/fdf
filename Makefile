# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/09 09:46:03 by fkoehler          #+#    #+#              #
#    Updated: 2016/03/21 15:47:35 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c ./src

SRC = init.c main.c manage_file.c parse.c store.c

NAME = fdf

FLAGS = -Wall -Werror -Wextra

LIBDIR = ./libft/

INCLUDES = $(LIBDIR)includes/

LIB = $(LIBDIR)libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		gcc $(FLAGS) $(OBJ) -framework OpenGL -framework AppKit -lmlx -L$(LIBDIR) -lft -o $@

$(LIB):
	make -C $(LIBDIR)

%.o: %.c
	gcc $(FLAGS) -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
