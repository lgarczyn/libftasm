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

NAME = libftasm.a

TEST_NAME = a.out

SRC = asm.s
		
OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(SRC))))

GCC_FLAGS = -g -no-pie -Wno-implicit-function-declaration 

all: $(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	TARGET = -f elf64
	DEFINE = -D LINUX
else
	ifeq ($(UNAME_S),Darwin)
		TARGET = -f macho64
	else
		$(error Incompatible Platform)
	endif
endif

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	gcc $(GCC_FLAGS) $(DEFINE) main.c $(NAME) -o $(TEST_NAME)

obj/%.o: src/%.s
	mkdir -p obj
	nasm $(TARGET) $(DEFINE) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean:
	rm -f $(TEST_NAME) $(NAME)

re: fclean all
