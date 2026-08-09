# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/06 14:33:42 by eroque-d          #+#    #+#              #
#    Updated: 2026/08/02 13:52:49 by jobezerr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./include -I./libft/includes

LIB_DIR     = libft
LIB_NAME    = $(LIB_DIR)/libft.a

SRC         = src/main.c						\
			  src/program.c					\
			  src/stack/stack_init.c			\
			  src/stack/stack_modifiers.c		\
			  src/operations/push.c				\
			  src/operations/swap.c				\
			  src/operations/rotate.c			\
			  src/operations/rr.c				\
			  src/operations/output.c			\
			  src/parsing/parsing.c				\
			  src/parsing/parse_integer.c		\
			  src/parsing/indexing.c			\
			  src/benchmark/benchmark.c			\
			  src/algorithms/sort_small.c		\
			  src/algorithms/sort_simple.c		\
			  src/algorithms/sort_medium.c		\
			  src/algorithms/sort_complex.c		\
			  src/algorithms/sort_adaptive.c

OBJS        = $(SRC:.c=.o)

all: $(NAME)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(LIB_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_NAME) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
