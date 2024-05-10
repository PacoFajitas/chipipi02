# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 22:16:37 by tfiguero          #+#    #+#              #
#    Updated: 2024/04/05 22:17:10 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRC_FILES = main.cpp\
			Fixed.cpp
			
OBJ_DIR = objs/
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES = $(SRC_FILES:.cpp=.d)
DEPS = $(addprefix $(OBJ_DIR), $(DEP_FILES))

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD
RM = rm -f
INCLUDE = -I ./

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re