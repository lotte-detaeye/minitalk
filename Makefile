# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 17:11:41 by lde-taey          #+#    #+#              #
#    Updated: 2024/04/28 19:16:14 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAMESV = server
CFLAGS = -Werror -Wall -Wextra

SRCS = client.c
SRCSSV = server.c

OBJS = $(SRCS:.c=.o)
OBJSSV = $(SRCSSV:.c=.o)

$(NAME) : $(OBJS)
	make -C ./libft
	cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(NAMESV) : $(OBJSSV)
	make -C ./libft
	cc $(CFLAGS) $(OBJSSV) libft/libft.a -o $(NAMESV)

.PHONY : all clean fclean re

all : $(NAME) $(NAMESV)

clean : 
	make clean -C ./libft
	rm -f $(OBJS) $(OBJSSV)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAMESV)

re : fclean all
