# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 14:40:17 by fde-capu          #+#    #+#              #
#    Updated: 2021/04/26 15:36:44 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	=	/bin/sh
NAME	=	megaphone
SRCS	=	megaphone.cpp
CC		=	clang++ -std=c++98
CCFLAGS	=	-Wall -Werror -Wextra -g
OBJS	=	$(SRCS:.cpp=.o)
HEAD	=	
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
t:			ta tb tc
ta:			all
	./$(NAME) "shhhhh... I think the students are asleep..."
tb:			all
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
tc:			all
	./$(NAME)
rt:			re t
v:			va vb vc
va:			all
	$(VAL) ./$(NAME) "shhhhh... I think the students are asleep..."
vb:			all
	$(VAL) ./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
vc:			all
	$(VAL) ./$(NAME)
vf:			vfa vfb vfc
vfa:		all
	$(VAL) $(VALFLAG) ./$(NAME) "shhhhh... I think the students are asleep..."
vfb:		all
	$(VAL) $(VALFLAG) ./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
vfc:		all
	$(VAL) $(VALFLAG) ./$(NAME)
	
