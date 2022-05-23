# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 00:16:18 by seyu              #+#    #+#              #
#    Updated: 2021/12/18 03:14:17 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -f
MKDIR	=	mkdir -p

NAME	=	libft.a

# ----------------------------------
# Source files
# ----------------------------------

SRCS = $(subst sources/, , $(wildcard **/*.c))

# Part 1. C library functions

# SRCS	+=	ft_memset.c \
# 			ft_bzero.c \
# 			ft_memcpy.c \
# 			ft_memccpy.c \
# 			ft_memmove.c \
# 			ft_memchr.c \
# 			ft_memcmp.c \
# 			ft_strlen.c \
# 			ft_strlcpy.c \
# 			ft_strlcat.c \
# 			ft_strchr.c \
# 			ft_strrchr.c \
# 			ft_strnstr.c \
# 			ft_strncmp.c \
# 			ft_atoi.c \
# 			ft_isalpha.c \
# 			ft_isdigit.c \
# 			ft_isalnum.c \
# 			ft_isascii.c \
# 			ft_isprint.c \
# 			ft_toupper.c \
# 			ft_tolower.c \
# 			ft_calloc.c \
# 			ft_strdup.c

# # Part 2. Additional functions

# SRCS	+=	ft_substr.c \
# 			ft_strjoin.c \
# 			ft_strtrim.c \
# 			ft_split.c \
# 			ft_itoa.c \
# 			ft_strmapi.c \
# 			ft_putchar_fd.c \
# 			ft_putstr_fd.c \
# 			ft_putendl_fd.c \
# 			ft_putnbr_fd.c

# # Bonus Part. List functions

# SRCS	+=	ft_lstnew.c \
# 			ft_lstadd_front.c \
# 			ft_lstsize.c \
# 			ft_lstlast.c \
# 			ft_lstadd_back.c \
# 			ft_lstdelone.c \
# 			ft_lstclear.c \
# 			ft_lstiter.c \
# 			ft_lstmap.c

# My Bonus Functions

SRCS	+=	\

# ----------------------------------
# Object files
# ----------------------------------

OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# ----------------------------------
# Directories and Paths
# ----------------------------------

INC_DIR	=	./includes
SRC_DIR	=	./sources
OBJ_DIR	=	./objects

VPATH	=	$(SRC_DIR)

# ----------------------------------
# Compiler and flags
# ----------------------------------

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# ----------------------------------
# Rules
# ----------------------------------

all:		$(NAME)

$(OBJ_DIR):
			@$(MKDIR) $@

$(OBJ_DIR)/%.o: %.c
			@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME):	$(OBJ_DIR) $(OBJS)
			@ar rc $(NAME) $(OBJS)

clean:
			@$(RM) -r $(OBJ_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
