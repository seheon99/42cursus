# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 14:21:27 by seyu              #+#    #+#              #
#    Updated: 2020/07/30 14:02:00 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c \
			ft_calloc.c \
			ft_convert_unicode_to_utf8.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_llabs.c \
			ft_llmax.c \
			ft_llmin.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strtol.c \
			ft_strtoll.c \
			ft_ulltostr.c \
			ft_wcslen.c
OBJS	=	$(SRCS:.c=.o)

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
