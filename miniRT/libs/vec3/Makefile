# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 01:32:01 by seyu              #+#    #+#              #
#    Updated: 2020/10/29 02:35:12 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC	=	srcs/
SRCS	=	$(wildcard $(DIR_SRC)/*.c)
OBJS	=	$(SRCS:.c=.o)

NAME	=	libvec3.a

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g -Iincludes

RM		=	rm -f

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
