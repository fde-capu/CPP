# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 16:17:08 by fde-capu          #+#    #+#              #
#    Updated: 2021/07/28 16:17:40 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	span
SRCS	=	span.cpp main.cpp
HEAD	=	span.hpp
SHELL	=	/bin/sh
CC		=	clang++ -std=c++98
CCFLAGS	=	-Wall -Werror -Wextra -g
OBJS	=	$(SRCS:.cpp=.o)
VAL		=	valgrind
VALFLAG	=	--tool=memcheck \
			--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--show-reachable=yes
all:		$(NAME)
$(NAME):	$(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)
$(OBJS):	%.o : %.cpp $(HEAD)
	$(CC) $(CCFLAGS) -o $@ -c $<
clean:
	-rm -f $(OBJS)
fclean:		clean
	-rm -f $(NAME)
re:			fclean all
rt:			re t
vf:			all
	$(VAL) $(VALFLAG) ./$(NAME)
t:			all
	./$(NAME)
v:			all
	$(VAL) ./$(NAME)
