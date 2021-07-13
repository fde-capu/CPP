# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 14:55:48 by fde-capu          #+#    #+#              #
#    Updated: 2021/07/13 18:06:24 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	set_the_world_on_fire.out
SRCS	=	AWeapon.cpp PlasmaRifle.cpp \
			PowerFist.cpp Enemy.cpp \
			SuperMutant.cpp RadScorpion.cpp \
			Character.cpp main.cpp
HEAD	=	AWeapon.hpp PlasmaRifle.hpp \
			PowerFist.hpp Enemy.hpp \
			SuperMutant.hpp RadScorpion.hpp \
			Character.hpp
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

