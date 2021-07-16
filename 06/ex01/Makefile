# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 11:34:47 by fde-capu          #+#    #+#              #
#    Updated: 2021/07/16 11:34:47 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	serialize
SRCS	=	main.cpp Data.cpp plot.cpp CoplienTest.cpp
HEAD	=	Data.hpp header.hpp CoplienTest.hpp
SHELL	=	/bin/sh
CC		=	clang++ -std=c++98
CCFLAGS	=	-Wall -Werror -Wextra -Wno-unused -Wconversion -g
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
