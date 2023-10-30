# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 14:46:17 by isbraz-d          #+#    #+#              #
#    Updated: 2023/10/24 12:11:31 by isbraz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror 

SRCS	= 	src/main.c src/moves.c src/list_utils.c src/utils.c src/sorte_little.c src/checker.c \
		src/sorte_large.c src/utils2.c

OBJS	=	$(SRCS:%.c=%.o)

RM			=	rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:		$(NAME)

$(NAME):	$(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:
	@echo $(PURPLE) "[Cleaning...]" $(EOC) 
	$(RM) $(OBJS)

fclean:		clean
	@echo $(PURPLE) "[FCleaning...]" $(EOC)
	$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re