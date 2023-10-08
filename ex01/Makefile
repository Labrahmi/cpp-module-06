# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:10:35 by ylabrahm          #+#    #+#              #
#    Updated: 2023/10/08 07:59:10 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Serializer.cpp
OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix obj/, $(OBJS))

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = serializer

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

obj/%.o: %.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -rf obj/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re