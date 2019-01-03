# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:11:22 by lgarczyn          #+#    #+#              #
#    Updated: 2018/01/26 00:20:12 by lgarczyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftasm

SRC = 

INC = 
		
OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(SRC))))

LIB = 

DEB = 

OPT =

FLG =

all: $(NAME)

$(NAME):$(OBJ)
	dqwwd

obj/%.o: src/%.c
	nasm

lib:
	rm -rf $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: lib
	rm -f 

re: fclean all

libre: lib all

optire: fclean opti
