# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarhdad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 03:59:55 by ybarhdad          #+#    #+#              #
#    Updated: 2019/11/07 16:22:02 by ybarhdad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME= libftprintf.a

SRCS=	ft_print_char.c ft_print_pointer.c ft_print_unsigned.c ft_proccessflags.c ft_print_hex.c ft_print_string.c ft_printf.c print_int.c

LIBFT=	ft_memset.c			ft_bzero.c			ft_memcpy.c			\
			ft_memccpy.c	 	ft_memmove.c 		ft_memchr.c			\
			ft_memcmp.c 		ft_strlen.c 		ft_strdup.c			\
			ft_strlcpy.c	 	ft_strlcat.c 		ft_strchr.c			\
			ft_strrchr.c 		ft_strnstr.c 		ft_strncmp.c		\
			ft_atoi.c 			ft_isalpha.c 		ft_isdigit.c		\
			ft_isalnum.c	 	ft_isascii.c 		ft_isprint.c		\
			ft_toupper.c 		ft_tolower.c 		ft_strmapi.c		\
			ft_strjoin.c 		ft_strtrim.c 		ft_split.c			\
			ft_itoa.c 			ft_putchar_fd.c 	ft_putstr_fd.c		\
			ft_putendl_fd.c 	ft_putnbr_fd.c		ft_calloc.c			\
			ft_substr.c	ft_iswhitespace.c	ft_lltoa_base.c ft_ulltoa_base.c ft_ulltoa_base.c ft_lltoa_base.c ft_utoa.c

OBJS=	$(SRCS:.c=.o) $(LIBFT:.c=.o)

SRCS_PATH=	sources/
LIBFT_PATH=	libft/

CC= gcc

CFLAGS= -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
