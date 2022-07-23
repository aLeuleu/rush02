# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macourio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 10:44:22 by macourio          #+#    #+#              #
#    Updated: 2022/07/23 10:52:33 by macourio         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror
SRCS    =   $(wildcard $(SRCDIR)/.c)
SRCDIR  =   srcs
OBJDIR  =   obj
OBJ     =   $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
NAME    =   rush-02

all:    $(NAME)

$(NAME):    $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)/*.o

fclean:     clean
	rm -rf $(NAME)

re:         fclean all

.PHONY: clean fclean re 
