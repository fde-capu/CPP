# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 09:33:18 by fde-capu          #+#    #+#              #
#    Updated: 2021/07/20 16:12:10 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	identify_real_type
SRCS	=	main.cpp
HEAD	=	Base.hpp A.hpp B.hpp C.hpp
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
