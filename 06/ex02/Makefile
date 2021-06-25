# ********************************************* #
#                                               #
#                      :|||::|||:||||:::||||||  #
#  Makefile            :|::||::|::|:||::::||:|  #
#                      |:|:|:::|::::::|:|:|||:  #
#                                               #
#                                               #
#  C20210622150759 ::|::|                       #
#  U20210622153154 |:|:::                       #
#                                               #
# ********************************************* #

NAME	=	identify_real_type
SRCS	=	Base.cpp main.cpp
HEAD	=	Base.hpp A.hpp B.hpp C.hpp
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
