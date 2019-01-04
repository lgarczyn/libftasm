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

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	TARGET = elf64
	DEFINE = -DPREFIX=_ft_
else
	ifeq ($(UNAME_S),Darwin)
		TARGET = macho64
		DEFINE = -DPREFIX=_ft_
	else
		$(error Incompatible Platform)
	endif
endif


$(NAME):$(OBJ)
	nasm -f $(TARGET) templates.txt -l a.lst -o a.o
	gcc -g -no-pie -Wno-implicit-function-declaration $(DEFINE) main.c a.o

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
