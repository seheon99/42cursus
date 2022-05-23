# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 00:16:18 by seyu              #+#    #+#              #
#    Updated: 2021/02/01 19:51:05 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -f
MKDIR	=	mkdir -p

NAME	=	libft.a

# ----------------------------------
# Source files
# ----------------------------------

# Part 1. C library functions

SRCS	+=	ft_memset.c \
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
			ft_strdup.c

# Part 2. Additional functions

SRCS	+=	ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

# Bonus Part. List functions

SRCS	+=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

# My Bonus Functions

SRCS	+=	ft_append_bonus.c \
			ft_atof_bonus.c \
			ft_intlog_bonus.c \
			ft_intlogn_bonus.c \
			ft_isoctal_bonus.c \
			ft_ishex_bonus.c \
			ft_isspace_bonus.c \
			ft_isupper_bonus.c \
			ft_islower_bonus.c \
			ft_itostr_bonus.c \
			ft_list_find_bonus.c \
			ft_list_remove_if_bonus.c \
			ft_lstdel_first_bonus.c \
			ft_lstdel_last_bonus.c \
			ft_lstdel_one_bonus.c \
			ft_llabs_bonus.c \
			ft_llmax_bonus.c \
			ft_llmin_bonus.c \
			ft_lltostr_bonus.c \
			ft_ltostr_bonus.c \
			ft_print_memory_bonus.c \
			ft_strcmp_bonus.c \
			ft_strncpy_bonus.c \
			ft_strndup_bonus.c \
			ft_strnpop_bonus.c \
			ft_strtol_bonus.c \
			ft_strtoll_bonus.c \
			ft_strpop_bonus.c \
			ft_ulltostr_bonus.c

# ----------------------------------
# Object files
# ----------------------------------

OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# ----------------------------------
# Directories and Paths
# ----------------------------------

INC_DIR	=	./includes
SRC_DIR	=	./sources
OBJ_DIR	=	./objs

VPATH	=	$(SRC_DIR)

# ----------------------------------
# Compiler and flags
# ----------------------------------

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g3

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
			@$(RM) *\ *

re:			fclean all
