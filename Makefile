# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 10:11:07 by mapoirie          #+#    #+#              #
#    Updated: 2023/06/29 10:13:18 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror
RM = rm -fr
SRC = check_error.c\
do_instru.c\
do_instru2.c\
fill_stack.c\
push_swap.c\
sort_3.c\
sort_big.c\
sort_big2.c\
sort_small.c\
split.c\
swap_utils.c\
swap_utils2.c\
swap_utils3.c\
write_instru.c\
write_instru2.c\
write_instru3.c

SRC_BONUS = checker.c\
checker_error.c\
checker_check_error.c\
checker_utils.c\
checker_utils2.c\
get_next_line.c\
split.c\
fill_stack.c\
do_instru.c\
do_instru2.c\
checker_start.c

OBJ = $(SRC: .c=.o)

OBJ_BONUS = $(SRC_BONUS: .c=.o)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

$(NAME_BONUS): $(OBJ)
	cc -o $(NAME_BONUS) $(OBJ_BONUS)

all : $(NAME)

bonus : $(NAME_BONUS)

%.o : %.c
	$(CC) -I $(CFLAGS) -o $@ -c $< 

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re