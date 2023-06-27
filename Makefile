# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 10:11:07 by mapoirie          #+#    #+#              #
#    Updated: 2023/06/26 13:45:33 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
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

OBJ = $(SRC: .c=.o)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c
	$(CC) -I $(CFLAGS) -o $@ -c $< 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re