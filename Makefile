# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 09:37:43 by fjimenez          #+#    #+#              #
#    Updated: 2021/03/08 10:23:12 by fjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m
PURPLE = \033[0;35m
YELLOW = \033[0;33m

N_CHECKER = checker

N_PUSH_SWAP = push_swap

INC = push_swap.h

GCC = gcc -Wall -Wextra -Werror

RM = rm -rf

SRC_CHECKER =	checker \
				utils \
				push_stack \
				pop_stack \
				handle_cmd \

SRC_PUSH_SWAP = push_swap \
				utils \
				push_stack \
				pop_stack \
				handle_cmd \

CF_CHECKER = $(addsuffix .c, $(SRC_CHECKER))

OF_CHECKER = $(addsuffix .o, $(SRC_CHECKER))

CF_PUSH_SWAP = $(addsuffix .c, $(SRC_PUSH_SWAP))

OF_PUSH_SWAP = $(addsuffix .o, $(SRC_PUSH_SWAP))

LIBFT = libft/libft.a

M_LIBFT = make -C libft/

GNL = GNL/get_next_line.c GNL/get_next_line_utils.c

all: $(N_CHECKER) $(N_PUSH_SWAP)

$(N_CHECKER): $(OF_CHECKER) $(INC)
	@$(M_LIBFT)
	@$(GCC) $(CF_CHECKER) $(LIBFT) $(GNL) -o $(N_CHECKER)
	@echo "$(RED)(CHECKER)$(BLUE)====CREATED====$(RESET)"

$(N_PUSH_SWAP): $(OF_PUSH_SWAP) $(INC)
	@$(GCC) $(CF_PUSH_SWAP) $(LIBFT) $(GNL) -o $(N_PUSH_SWAP)
	@echo "$(RED)(PUSH_SWAP)$(BLUE)====CREATED====$(RESET)"

clean:
	@$(RM) $(OF_CHECKER) $(OF_PUSH_SWAP)
	@make -C libft/ fclean

fclean: clean
	@$(RM) $(N_CHECKER) $(N_PUSH_SWAP)
	@echo "$(RED)(CHECKER && PUSH_SWAP)$(YELLOW)====REMOVED====$(RESET)"

re : fclean all