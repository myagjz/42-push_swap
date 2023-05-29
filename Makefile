# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 18:33:07 by myagiz            #+#    #+#              #
#    Updated: 2023/05/29 15:09:29 by myagiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= push_swap
CC      	= gcc
CFLAGS  	= -Wall -Werror -Wextra -g

SRC_PATH 	= src/
OBJ_PATH 	= obj/

SRC1 		= main.c
SRCS1 		= $(addprefix $(SRC_PATH), $(SRC1))
OBJ1 		= $(SRC1:.c=.o)
OBJS1 		= $(addprefix $(OBJ_PATH), $(OBJ1))

SRC2 		= input_check.c input_check_utils.c \
			initialization.c push_swap.c \
			stack.c split.c \
			swap.c push.c rotate.c reverse_rotate.c \
			sort_tiny.c sort.c \
			position.c cost.c do_move.c \
			utils.c
SRCS2 		= $(addprefix $(SRC_PATH), $(SRC2))
OBJ2 		= $(SRC2:.c=.o)
OBJS2 		= $(addprefix $(OBJ_PATH), $(OBJ2))

INCS 		= -I ./includes/

BONUS_SRC 	= check/check.c \
				check/check_utils.c \
				check/get_next_line.c \
				check/get_next_line_utils.c
BONUS_OBJS 	= $(BONUS_SRC:.c=.o)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS1) $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS1) $(OBJS2) -o $(NAME)

bonus: $(BONUS_OBJS) $(OBJS2)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS2) -o checker

clean:
	rm -rf $(OBJ_PATH)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f checker

re: fclean all

.PHONY: all clean fclean re bonus
