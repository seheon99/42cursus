# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 20:01:40 by seyu              #+#    #+#              #
#    Updated: 2020/10/28 02:25:42 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_calloc.c \
				ft_strdup.c \
				\
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				\
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				\
				ft_isspace.c \
				ft_isupper.c \
				ft_islower.c \
				ft_strtol.c \
				ft_strtoll.c \
				ft_itostr.c \
				ft_ltostr.c \
				ft_lltostr.c \
				ft_ulltostr.c \
				ft_print_memory.c \
				ft_intlogn.c \
				ft_intlog.c \
				ft_llabs.c \
				ft_llmax.c \
				ft_llmin.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	libft.a
CC			=	clang
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)

bonus:		$(NAME)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
