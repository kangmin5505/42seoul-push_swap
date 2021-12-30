# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 18:53:50 by kangkim           #+#    #+#              #
#    Updated: 2021/12/30 23:02:06 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END	=	\033[0;0m
_GREEN	=	\033[0;32m

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
INCLUDES = includes
FILE = main				\
		parse_args		\
		stack			\
		operators		\
		push_swap		\
		push_swap_utils	\

SRCS_DIR = srcs
OBJS_DIR = objs
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILE)))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILE)))
LIBFT_DIR = libft
LIBFT_A = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT_A)
	@echo "$(_GREEN)[ Try to make $(NAME) ]$(_END)"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $^
	@echo "$(_GREEN)[ Done ]$(_END)"

$(LIBFT_DIR)/$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
