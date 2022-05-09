# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 15:11:37 by mbarutel          #+#    #+#              #
#    Updated: 2022/05/07 15:15:31 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GERR = gcc -c -Wall -Wextra -Werror

SRCS = ft_printf.c
SRCS += ft_hex.c
SRCS += ft_str_chr_specifier.c
SRCS += nbr_specifier.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@$(GERR) $(SRCS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all