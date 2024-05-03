# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 17:11:41 by lde-taey          #+#    #+#              #
#    Updated: 2024/04/17 15:57:03 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CFLAGS = -Werror -Wall -Wextra

SRCS = client.c \
	server.c

OBJS = $(SRCS:.c=.o)

$(NAME) :
	make -C ./libft
	cc $(CFLAGS) client.c libft/libft.a -o client
	cc $(CFLAGS) server.c libft/libft.a -o server

.PHONY : all clean fclean re

all : $(NAME)

clean : 
	make clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C ./libft
	rm -f server client

re : fclean make