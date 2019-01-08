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

NAME = libfts.a

TEST_NAME = a.out

SRC =	ft_isalnum.s\
		ft_isalpha.s\
		ft_isascii.s\
		ft_isdigit.s\
		ft_islower.s\
		ft_isprint.s\
		ft_iscntrl.s\
		ft_isupper.s\
		ft_isspace.s\
		ft_isblank.s\
		ft_isxdigit.s\
		ft_tolower.s\
		ft_toupper.s\
		ft_bzero.s\
		ft_memcpy.s\
		ft_memset.s\
		ft_strdup.s\
		ft_strcat.s\
		ft_strlen.s\
		ft_puts.s\
		ft_cat.s\
		symbols.s

OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(SRC))))

FLAGS_GCC =  -Wno-implicit-function-declaration 

all: $(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS_NASM = -f elf64
	FLAGS = -D LINUX
	FLAGS_GCC = $(FLAGS_GCC) -no-pie
else
	ifeq ($(UNAME_S),Darwin)
		FLAGS_NASM = -f macho64 --prefix _
	else
		$(error Incompatible Platform)
	endif
endif

$(NAME):$(OBJ) main.c
	rm -rf $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	gcc $(FLAGS_GCC) $(FLAGS) main.c $(NAME) -o $(TEST_NAME)

obj/%.o: src/%.s
	mkdir -p obj
	nasm $(FLAGS_NASM) $(FLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(TEST_NAME) $(NAME)

re: fclean all
