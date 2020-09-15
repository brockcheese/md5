# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpace <bpace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 23:49:38 by bpace             #+#    #+#              #
#    Updated: 2019/10/06 20:31:09 by bpace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
		ft_itoa.c \
		ft_bzero.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memset.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strcap.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strlen.c \
		ft_strlow.c \
		ft_strmap.c \
		ft_strnew.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_lstiter.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_putchar.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putendl.c \
		ft_foreach.c \
		ft_list_at.c \
		ft_striter.c \
		ft_strsplit.c \
		ft_memalloc.c \
		ft_striteri.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_list_size.c \
		ft_list_last.c \
		ft_lstdelone.c \
		ft_putendl_fd.c \
		ft_putchar_fd.c \
		ft_atolonglong.c \
		ft_list_push_back.c \
		get_next_line/get_next_line.c \

NAME = libft.a

all: $(NAME)

$(NAME):
	@make -C ft_printf re
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rc libft.a *.o ft_printf/srcs/*.o

clean:
		@make -C ft_printf clean
		@/bin/rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME) ft_printf/ft_printf.a

re: fclean all
