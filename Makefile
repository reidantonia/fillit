# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 10:00:01 by mjoubert          #+#    #+#              #
#    Updated: 2017/11/27 22:17:58 by areid            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = sources

SRC_NAME = main.c ft_solver.c ft_read.c ft_test1.c ft_test2.c ft_error.c ft_stock.c ft_tet_red.c ft_board_calc.c ft_print_map.c

CPPFLAGS = -Iincludes

OBJ_PATH = sources

CFLAGS = -Wextra -Werror -Wall

CC = clang

LDFLAGS = -Llibft

LDLIBS = -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	    @mkdir $(OBJ_PATH) 2> /dev/null
		    $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean: 
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re : fclean all

.PHONY : all, fclean, clean, re

norme :
	norminette $(SRCS)
	norminette $(INC_PATH)*.h
