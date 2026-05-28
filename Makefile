# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 08:21:01 by alex              #+#    #+#              #
#    Updated: 2026/05/28 07:00:04 by alejandro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c
HEADERS = ft_printf.h
OBJS = $(SRCS:.c=.o)
TEST_DIR = test
TEST_FILES = $(TEST_DIR)/test.c
TEST_BIN = test_printf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_BIN)

$(TEST_BIN): $(NAME) $(TEST_MAIN)
	$(CC) $(CFLAGS) -I. $(TEST_FILES) $(NAME) -o $(TEST_BIN)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re test
