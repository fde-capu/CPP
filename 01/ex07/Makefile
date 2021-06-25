# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 13:17:30 by fde-capu          #+#    #+#              #
#    Updated: 2021/06/02 13:09:09 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	=	/bin/sh
NAME	=	replace
SRCS	=	Replace.cpp ft_cpp.cpp
HEAD	=	ft_cpp.hpp
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
t:			all
	-./$(NAME)
	@echo "Above run w/o arguments expected fo fail."
	@echo "Use \`make tX\` and \`make tXv\` (X = 1-4)"
	@echo "and follow the respective \`.sh\` files."
	@echo "There is also a \`make terror\` and a \`make terrorv\`."
rt:			re t
v:			all
	$(VAL) ./$(NAME)
vf:			all
	$(VAL) $(VALFLAG) ./$(NAME)
terror:		all
	./test_error.sh
terrorv:	all
	./test_error_valgrind.sh
t1:			all
	./test_1.sh
t1v:		all
	./test_1_valgrind.sh
t2:			all
	./test_2.sh
t2v:		all
	./test_2_valgrind.sh
t3:			all
	./test_3.sh
t3v:		all
	./test_3_valgrind.sh
t4:			all
	./test_4.sh
t4v:		all
	./test_4_valgrind.sh
