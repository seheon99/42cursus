# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:32:52 by seyu              #+#    #+#              #
#    Updated: 2022/01/26 02:00:15 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f
CC = clang
CFLAGS = -Wall -Wextra -Werror

SULLY_MASS = $(wildcard Sully_*.c)

all: colleen grace sully

colleen: Colleen.o
	$(CC) $(CFLAGS) Colleen.o -o Colleen

grace: Grace.o
	$(CC) $(CFLAGS) Grace.o -o Grace

sully_mass: $(SULLY_MASS:.c=.o)
	$(CC) $(CFLAGS) $< -o $(basename $<)

sully: Sully.o
	$(CC) $(CFLAGS) Sully.o -o Sully

clean:
	$(RM) *.o
	$(RM) Grace_kid.c
	$(RM) $(SULLY_MASS)

fclean: clean
	$(RM) Colleen Grace Sully

re: fclean all
