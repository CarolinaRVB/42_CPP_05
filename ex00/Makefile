# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 14:14:43 by crebelo-          #+#    #+#              #
#    Updated: 2024/11/20 07:34:46 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex00

SRC := 	Bureaucrat.cpp \
		main.cpp

OBJ := $(SRC:.cpp=.o)

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

GREEN := \033[0;32m

all: $(OBJ) $(NAME)

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(GREEN) Compiling ex00 ... "
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Done! "

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.phony: all clean fclean re