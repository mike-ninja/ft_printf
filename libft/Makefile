# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:58:30 by mbarutel          #+#    #+#              #
#    Updated: 2021/12/13 23:01:35 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GERR = gcc -c -Wall -Wextra -Werror

SRCS = srcs/ft_memset.c 
SRCS += srcs/ft_bzero.c
SRCS += srcs/ft_memcpy.c
SRCS += srcs/ft_memccpy.c
SRCS += srcs/ft_memmove.c
SRCS += srcs/ft_memchr.c
SRCS += srcs/ft_memcmp.c
SRCS += srcs/ft_strlen.c
SRCS += srcs/ft_strdup.c
SRCS += srcs/ft_strcpy.c
SRCS += srcs/ft_strncpy.c
SRCS += srcs/ft_strcat.c
SRCS += srcs/ft_strncat.c
SRCS += srcs/ft_strlcat.c
SRCS += srcs/ft_strchr.c
SRCS += srcs/ft_strrchr.c
SRCS += srcs/ft_strstr.c
SRCS += srcs/ft_strnstr.c
SRCS += srcs/ft_strcmp.c
SRCS += srcs/ft_strncmp.c
SRCS += srcs/ft_atoi.c
SRCS += srcs/ft_isalpha.c
SRCS += srcs/ft_isdigit.c
SRCS += srcs/ft_isalnum.c
SRCS += srcs/ft_isascii.c
SRCS += srcs/ft_isprint.c
SRCS += srcs/ft_toupper.c
SRCS += srcs/ft_tolower.c
SRCS += srcs/ft_memalloc.c
SRCS += srcs/ft_memdel.c
SRCS += srcs/ft_strnew.c
SRCS += srcs/ft_strdel.c
SRCS += srcs/ft_strclr.c
SRCS += srcs/ft_striter.c
SRCS += srcs/ft_striteri.c
SRCS += srcs/ft_strmap.c
SRCS += srcs/ft_strmapi.c
SRCS += srcs/ft_strequ.c
SRCS += srcs/ft_strnequ.c
SRCS += srcs/ft_strsub.c
SRCS += srcs/ft_strjoin.c
SRCS += srcs/ft_strtrim.c
SRCS += srcs/ft_strsplit.c
SRCS += srcs/ft_itoa.c
SRCS += srcs/ft_putchar.c
SRCS += srcs/ft_putstr.c
SRCS += srcs/ft_putendl.c
SRCS += srcs/ft_putnbr.c
SRCS += srcs/ft_putchar_fd.c
SRCS += srcs/ft_putstr_fd.c
SRCS += srcs/ft_putendl_fd.c
SRCS += srcs/ft_putnbr_fd.c
SRCS += srcs/ft_lstnew.c
SRCS += srcs/ft_lstdelone.c
SRCS += srcs/ft_lstdel.c
SRCS += srcs/ft_lstadd.c
SRCS += srcs/ft_lstaddback.c
SRCS += srcs/ft_lstiter.c
SRCS += srcs/ft_lstmap.c
SRCS += srcs/ft_del.c
SRCS += srcs/ft_calloc.c
SRCS += srcs/ft_strlcpy.c
SRCS += srcs/ft_lstlast.c
SRCS += srcs/ft_lstsize.c
SRCS += srcs/ft_realloc.c
SRCS += srcs/ft_strtok.c
SRCS += srcs/ft_strsep.c

OBJS = ft_memset.o 
OBJS += ft_bzero.o
OBJS += ft_memcpy.o
OBJS += ft_memccpy.o
OBJS += ft_memmove.o
OBJS += ft_memchr.o
OBJS += ft_memcmp.o
OBJS += ft_strlen.o
OBJS += ft_strdup.o
OBJS += ft_strcpy.o
OBJS += ft_strncpy.o
OBJS += ft_strcat.o
OBJS += ft_strncat.o
OBJS += ft_strlcat.o
OBJS += ft_strchr.o
OBJS += ft_strrchr.o
OBJS += ft_strstr.o
OBJS += ft_strnstr.o
OBJS += ft_strcmp.o
OBJS += ft_strncmp.o
OBJS += ft_atoi.o
OBJS += ft_isalpha.o
OBJS += ft_isdigit.o
OBJS += ft_isalnum.o
OBJS += ft_isascii.o
OBJS += ft_isprint.o
OBJS += ft_toupper.o
OBJS += ft_tolower.o
OBJS += ft_memalloc.o
OBJS += ft_memdel.o
OBJS += ft_strnew.o
OBJS += ft_strdel.o
OBJS += ft_strclr.o
OBJS += ft_striter.o
OBJS += ft_striteri.o
OBJS += ft_strmap.o
OBJS += ft_strmapi.o
OBJS += ft_strequ.o
OBJS += ft_strnequ.o
OBJS += ft_strsub.o
OBJS += ft_strjoin.o
OBJS += ft_strtrim.o
OBJS += ft_strsplit.o
OBJS += ft_itoa.o
OBJS += ft_putchar.o
OBJS += ft_putstr.o
OBJS += ft_putendl.o
OBJS += ft_putnbr.o
OBJS += ft_putchar_fd.o
OBJS += ft_putstr_fd.o
OBJS += ft_putendl_fd.o
OBJS += ft_putnbr_fd.o
OBJS += ft_lstnew.o
OBJS += ft_lstdelone.o
OBJS += ft_lstdel.o
OBJS += ft_lstadd.o
OBJS += ft_lstaddback.o
OBJS += ft_lstiter.o
OBJS += ft_lstmap.o
OBJS += ft_del.o
OBJS += ft_calloc.o
OBJS += ft_strlcpy.o
OBJS += ft_lstlast.o
OBJS += ft_lstsize.o
OBJS += ft_realloc.o
OBJS += ft_strtok.o
OBJS += ft_strsep.o

all: $(NAME)

$(NAME):
	@$(GERR) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

test:
	@rm -rf test_program
	@gcc main.c -L. -lft -o test_program
	@leaks -atExit -- ./test_program