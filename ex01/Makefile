# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 14:14:43 by crebelo-          #+#    #+#              #
#    Updated: 2024/11/20 07:35:02 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex01

SRC := 	Bureaucrat.cpp \
		Form.cpp \
		main.cpp

OBJ := $(SRC:.cpp=.o)

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

GREEN := \033[0;32m

all: $(OBJ) $(NAME)

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(GREEN) Compiling ex01 ... "
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Done! "

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.phony: all clean fclean re