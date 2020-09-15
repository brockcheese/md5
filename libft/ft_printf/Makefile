# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpace <bpace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 22:50:43 by bpace             #+#    #+#              #
#    Updated: 2019/09/13 21:32:05 by bpace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/*.c \

NAME = ft_printf.a

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@mv *.o srcs/

clean:
	@/bin/rm -f srcs/*.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
