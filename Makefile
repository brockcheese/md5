# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpace <bpace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 16:54:31 by bpace             #+#    #+#              #
#    Updated: 2019/10/16 19:37:17 by bpace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCC = srcs/* \

NAME = ft_ssl

all: $(NAME)

$(NAME):
	@make -C libft re
	@gcc -Wall -Werror -Wextra $(SRCC) libft/libft.a -o ft_ssl

clean:
		@make -C libft clean

fclean:
		@make -C libft fclean
		@/bin/rm -f $(NAME)

re: fclean all
