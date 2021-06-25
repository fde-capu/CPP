# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 10:18:29 by fde-capu          #+#    #+#              #
#    Updated: 2021/05/21 16:58:49 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out
SRCS	=	Bureaucrat.cpp main.cpp Form.cpp Debs.cpp IGradeExceptions.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp Intern.cpp \
			RatcliffObershelpSimilarity.cpp
HEAD	=	Bureaucrat.hpp Form.hpp Debs.hpp IGradeExceptions.hpp \
			ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp Intern.hpp \
			RatcliffObershelpSimilarity.hpp
U_FILES =	home.txt
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
	-rm -f $(U_FILES)
re:			fclean all
rt:			re t
vf:			all
	$(VAL) $(VALFLAG) ./$(NAME)
t:			all
	./$(NAME)
v:			all
	$(VAL) ./$(NAME)

# Chil0id1 a;
# Parent * b = &a;
# Child2 * d = static_cast<Child2 *>(b);
#...or dynamic_cast.
#...or reinterpret_cast
#...or const_cast.
