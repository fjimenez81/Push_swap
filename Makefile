# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 09:37:43 by fjimenez          #+#    #+#              #
#    Updated: 2021/03/04 19:26:39 by fjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m
PURPLE = \033[0;35m
YELLOW = \033[0;33m

N_CHECKER = checker

INC = push_swap.h

GCC = gcc -Wall -Wextra -Werror

RM = rm -rf

SRC_CHECKER =	checker \
				utils \
				push_stack \
				pop_stack \
				handle_cmd \

CF_CHECKER = $(addsuffix .c, $(SRC_CHECKER))

OF_CHECKER = $(addsuffix .o, $(SRC_CHECKER))

LIBFT = libft/libft.a

M_LIBFT = make -C libft/

GNL = GNL/get_next_line.c GNL/get_next_line_utils.c

all: $(N_CHECKER)

$(N_CHECKER): $(OF_CHECKER) $(INC)
	@$(M_LIBFT)
	@$(GCC) $(CF_CHECKER) $(LIBFT) $(GNL) -o $(N_CHECKER)
	@echo "$(RED)(CHECKER)$(BLUE)====CREATED====$(RESET)"

clean:
	@$(RM) $(OF_CHECKER)
	@make -C libft/ fclean

fclean: clean
	@$(RM) $(N_CHECKER)
	@echo "$(RED)(CHECKER)$(YELLOW)====REMOVED====$(RESET)"

re : fclean all