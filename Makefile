# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 09:56:58 by sechang           #+#    #+#              #
#    Updated: 2018/09/29 21:23:12 by sechang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sechang.filler
FLAGS = -Wall -Wextra -Werror
CC = gcc
OPTION = -c -I
LIB = Libft/libft.a
SRC = main.c store_data.c analyze_it.c mymove.c
OBJ = $(SRC:.c=.o) 

vis: 
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -lncurses
run:
	./filler_vm -q -f maps/map02 -p1 "./sechang.filler -v" -p2 players/carli.filler
all: $(NAME)

$(NAME):
	make -C Libft/
	$(CC) -c $(FLAGS) $(SRC) 
	ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)

clean:
	make -C Libft/	clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C Libft/	fclean
	/bin/rm -f $(NAME)

re: fclean all
