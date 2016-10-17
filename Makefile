# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2016/01/26 19:09:26 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	alum1
SRC		=	src/alcu.c \
			src/affichage.c \
			src/init.c \
			src/get_next_line.c \
			src/creatlist.c
SRCO	=	$(SRC:.c=.o)
HEADERS	=	header
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[32mAlcu:\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERS)

$(NAME): $(SRCO)
	@make -C libft/
	@$(CC)  $(CFLAGS) -o $(NAME) $(SRCO) libft/libft.a
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m------- OK - AlCu --------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"

clean:
	@echo "\033[32mAlcu:\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C libft/
	@rm -f $(SRCO)

fclean:
	@echo "\033[32mAlcu:\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mAlcu:\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C libft/
	@rm -f $(NAME)

.PHONY: re clean fclean all
