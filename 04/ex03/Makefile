# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#              #
#    Updated: 2021/07/15 09:51:22 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bocal_fantasy
SRCS	=	AMateria.cpp main.cpp \
			MateriaSource.cpp Ice.cpp \
			Cure.cpp Character.cpp \
			PlanctonHoney.cpp HypnoGem.cpp \
			MuddyWaters.cpp
HEAD	=	AMateria.hpp IMateriaSource.hpp \
			MateriaSource.hpp ICharacter.hpp \
			Ice.hpp Cure.hpp Character.hpp \
			PlanctonHoney.hpp HypnoGem.hpp \
			MuddyWaters.hpp
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

