# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 09:56:58 by sechang           #+#    #+#              #
#    Updated: 2018/09/29 22:14:10 by sechang          ###   ########.fr        #
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
ventev:
	./filler_vm -f maps/map02 -p1 "./sechang.filler -v" -p2 players/carli.filler -q
vente:
	./filler_vm -f maps/map02 -p1 ./sechang.filler -p2 players/carli.filler
grandev:
	./filler_vm -f maps/map01 -p1 "./sechang.filler -v" -p2 players/carli.filler -q
grande:
	./filler_vm -f maps/map01 -p1 ./sechang.filler -p2 players/carli.filler
tallv:
	./filler_vm -f maps/map00 -p1 "./sechang.filler -v" -p2 players/carli.filler -q
tall:
	./filler_vm -f maps/map00 -p1 ./sechang.filler -p2 players/carli.filler
all: $(NAME)

$(NAME):
	make -C Libft/
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -lncurses

clean:
	make -C Libft/	clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C Libft/	fclean
	/bin/rm -f $(NAME)

re: fclean all
