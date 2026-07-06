# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/16 21:09:36 by eroque-d          #+#    #+#              #
#    Updated: 2026/07/02 12:22:29 by eroque-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./includes

SRCS_CORE   = 	src/lib/ft_isalpha.c						\
				src/lib/ft_isdigit.c						\
				src/lib/ft_isalnum.c						\
				src/lib/ft_isascii.c						\
				src/lib/ft_isprint.c						\
				src/lib/ft_strlen.c							\
				src/lib/ft_memset.c							\
				src/lib/ft_bzero.c							\
				src/lib/ft_memcpy.c							\
				src/lib/ft_memmove.c 						\
				src/lib/ft_strlcpy.c 						\
				src/lib/ft_strlcat.c						\
				src/lib/ft_toupper.c 						\
				src/lib/ft_tolower.c 						\
				src/lib/ft_strchr.c 						\
				src/lib/ft_strrchr.c 						\
				src/lib/ft_strncmp.c 						\
				src/lib/ft_memchr.c 						\
				src/lib/ft_memcmp.c 						\
				src/lib/ft_strnstr.c 						\
				src/lib/ft_atoi.c 							\
				src/lib/ft_calloc.c 						\
				src/lib/ft_strdup.c 						\
				src/lib/ft_substr.c 						\
				src/lib/ft_strjoin.c 						\
				src/lib/ft_strtrim.c 						\
				src/lib/ft_split.c							\
				src/lib/ft_itoa.c							\
				src/lib/ft_strmapi.c						\
				src/lib/ft_striteri.c						\
				src/lib/ft_putchar_fd.c						\
				src/lib/ft_putstr_fd.c						\
				src/lib/ft_putendl_fd.c						\
				src/lib/ft_putnbr_fd.c						\
				src/lib/ft_lstnew.c							\
				src/lib/ft_lstadd_front.c					\
				src/lib/ft_lstsize.c						\
				src/lib/ft_lstlast.c						\
				src/lib/ft_lstadd_back.c					\
				src/lib/ft_lstdelone.c						\
				src/lib/ft_lstclear.c						\
				src/lib/ft_lstiter.c						\
				src/lib/ft_lstmap.c
SRCS_PRINTF = 	src/ft_printf/ft_printf.c					\
				src/ft_printf/ft_print_char.c				\
				src/ft_printf/ft_print_hex.c				\
				src/ft_printf/ft_print_ints.c				\
				src/ft_printf/ft_print_utils.c
SRCS_GNL    = 	src/gnl/get_next_line.c						\
				src/gnl/get_next_line_utils.c				\
				src/gnl/get_next_line_bonus.c				\
				src/gnl/get_next_line_utils_bonus.c			\

SRCS        = $(SRCS_CORE) $(SRCS_PRINTF) $(SRCS_GNL)
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
