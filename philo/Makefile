# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 02:21:09 by gucamuze          #+#    #+#              #
#    Updated: 2022/02/20 17:11:56 by gucamuze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXEC_NAME		=	philo
CC				=	clang -Wall -Wextra -Werror
RM				=	rm -f

SRCS_PATH		=	./srcs/
					
SRC_FILES		=	${SRCS_PATH}main.c \
					${SRCS_PATH}utils.c\
					${SRCS_PATH}setup.c \
					${SRCS_PATH}threads.c \
					${SRCS_PATH}supervisor.c
					
SRC_OFILES		= 	$(SRC_FILES:.c=.o)

%.o: %.c
				$(CC) -g -Iincludes -c $< -o $@

all:			$(EXEC_NAME)

$(EXEC_NAME):	$(SRC_OFILES)
				$(CC) -g $(SRC_OFILES) -Iincludes -lpthread -o $(EXEC_NAME)
							
clean:
				$(RM) $(SRC_OFILES)

fclean:		clean
				$(RM) ${EXEC_NAME}

re:			fclean all

norminette:
			norminette srcs libft includes

.PHONY:	all clean fclean re norminette

