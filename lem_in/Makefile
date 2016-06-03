# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/30 08:57:47 by aleblanc          #+#    #+#              #
#    Updated: 2016/05/11 10:45:42 by aleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c				\
	  lem_read_map.c		\
	  lem_check_read.c		\
	  lem_stock.c			\
	  lem_check_enough.c	\
	  lem_build_map.c		\
	  lem_find_paths.c		\
	  lem_check_paths.c		\
	  lem_ant_trip.c		\
	  lem_select_paths.c	\
	  lem_inloop.c			\
	  lem_option.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(SRC) -Llibft/ -lft

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean:
	make fclean -C libft/
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
