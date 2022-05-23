# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 23:07:12 by seyu              #+#    #+#              #
#    Updated: 2021/07/02 16:40:13 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .c .o .h

NAME	=	pipex

CP		=	cp
RM		=	rm -f
MKDIR	=	mkdir -p
MV		=	mv
ECHO	=	/bin/echo

# ----------------------------------
# Directories and Paths
# ----------------------------------

DIR_INC	=	./inc
DIR_SRC	=	./src
DIR_OBJ	=	./obj

SUBDIRS	=	\
			parse \
			process \
			util \
			variable

VPATH	=	$(DIR_SRC) $(addprefix $(DIR_SRC)/, $(SUBDIRS))

# ----------------------------------
# Mandatory source files
# ----------------------------------

# Main source file

SRCS	=	pipex.c	\
			perror_return.c

SRCS	+=	buffer.c \
			parse_line.c \
			read_characters.c \
			read_quotes.c \
			read_token.c

SRCS	+=	process_execute.c \
			process_free.c \
			process_init.c \
			process_path.c

SRCS	+=	\
			ft_calloc.c \
			ft_memchr.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strncpy.c

SRCS	+=	variables.c

# ----------------------------------
# Object files
# ----------------------------------

OBJS	=	$(addprefix $(DIR_OBJ)/, $(SRCS:%.c=%.o))

# ----------------------------------
# Compiler and flags
# ----------------------------------

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
CLIBS	=

# ----------------------------------
# Echo Colors
# ----------------------------------

NOCOLOR		= $$'\033[0m'
RED			= $$'\033[31m'
GREEN		= $$'\033[32m'
ORANGE		= $$'\033[33m'
BLUE		= $$'\033[34m'
PURPLE		= $$'\033[35m'
CYAN		= $$'\033[36m'
LIGHTGRAY	= $$'\033[37m'
DARKGRAY	= $$'\033[90m'
LIGHTRED	= $$'\033[91m'
LIGHTGREEN	= $$'\033[92m'
YELLOW		= $$'\033[93m'
LIGHTBLUE	= $$'\033[94m'
LIGHTPURPLE	= $$'\033[95m'
LIGHTCYAN	= $$'\033[96m'
WHITE		= $$'\033[97m'

# ----------------------------------
# Echo Escape Characters
# ----------------------------------

LINE_CLEAR	= $$'\33[2K\r'

# ----------------------------------
# Rules
# ----------------------------------

all: $(NAME)

$(DIR_OBJ):
			@$(MKDIR) $@

$(DIR_OBJ)/%.o: %.c
			@$(ECHO) -n Compiling $(ORANGE)$< $(NOCOLOR)
			@$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@
			@$(ECHO) $(LINE_CLEAR)Compiled $(BLUE)$< $(GREEN)Successfully$(NOCOLOR)

$(NAME):	$(DIR_OBJ) $(OBJS)
			@$(ECHO) -n Making $(ORANGE)$(NAME)$(NOCOLOR) ...
			@$(CC) $(CFLAGS) $(CLIBS) -I$(DIR_INC) $(OBJS) -o $(NAME)
			@$(ECHO) $(LINE_CLEAR)Maked $(BLUE)$(NAME) $(GREEN)Successfully$(NOCOLOR)

clean:
			@$(RM) -r $(DIR_OBJ)
			@$(RM) -r $(DIR_OBJ)\ *
			@$(ECHO) Clean up all object files of $(RED)$(NAME)$(NOCOLOR)

fclean:		clean
			@$(RM) -r $(NAME)
			@$(RM) -r *\ *
			@$(ECHO) Removed $(RED)$(NAME)$(NOCOLOR)

bonus:		$(NAME)

re:			fclean $(NAME)
