# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 09:56:58 by sechang           #+#    #+#              #
#    Updated: 2018/09/29 20:40:04 by sechang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sechang.filler
FLAGS = -Wall -Wextra -Werror
CC = gcc
OPTION = -c -I
SRC = main.c store_data.c analyze_it.c mymove.c
OBJ = $(SRC:.c=.o) 

a:
	gcc *.c -o sechang.filler Libft/libft.a -lncurses
b:
	./filler_vm -f maps/map00 -p1 players/superjeannot.filler -p2 players/abanlin.filler
c:
	./filler_vm -f maps/map00 -p1 ./sechang.filler -p2 players/carli.filler 
d:
	./filler_vm -f maps/map01 -p1 ./sechang.filler -p2 players/carli.filler
e:
	./filler_vm -f maps/map02 -p1 ./sechang.filler -p2 players/carli.filler
f:
	./filler_vm -p2 players/carli.filler -p1 "./sechang.filler -v" -q -f maps/map02


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
