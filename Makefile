# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/06 14:33:42 by eroque-d          #+#    #+#              #
#    Updated: 2026/07/12 13:37:59 by eroque-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./include -I./libft/includes

LIB_DIR 	= libft
LIB_NAME	= $(LIB_DIR)/libft.a

SRC        = 	src/main.c 					\
				src/stack/stack_init.c 		\
				src/stack/stack_modifiers.c \
				src/operations/pb.c			\
				src/operations/pa.c
OBJS       = $(SRC:.c=.o)

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
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
