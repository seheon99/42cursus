# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 23:07:12 by seheon            #+#    #+#              #
#    Updated: 2021/02/01 19:50:56 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .c .o .h

NAME	=	minishell
FT		=	libft.a

CP		=	cp
RM		=	rm -f
MKDIR	=	mkdir -p
MV		=	mv
ECHO	=	/bin/echo

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

LINE_CLEAR	= $$'\33[2K'
RETURN		= $$'\r'

# ----------------------------------
# Mandatory source files
# ----------------------------------

# Main source file

SRCS	=	minishell.c

# Source files to built-in functions

SRCS	+=	\
			mini_echo.c \
			mini_cd.c \
			mini_pwd.c \
			mini_export.c \
			mini_unset.c \
			mini_env.c \
			mini_exit.c

# Source files to handle parsing

SRCS	+=	\
			buffer.c \
			parse_line.c \
			parse_redirect.c \
			parse_separator.c \
			read_characters.c \
			read_quotes.c \
			read_token.c \
			read_variables.c

# Source files to handle process

SRCS	+=	\
			execute_builtin.c \
			execute_path.c \
			process_execute.c \
			process_init.c

# Source files of the util functions

SRCS	+=	\
			print_prompt.c \
			print_debug.c \
			string_array.c

# Source files to handle environment variables

SRCS	+=	\
			variable_init.c \
			variable_operator.c

# Source files to handle errors

SRCS	+=	\
			error_handler.c

# Source files to handle the signals

SRCS	+=	\
			signal_handler.c

# ----------------------------------
# Object files
# ----------------------------------

OBJS	=	$(addprefix $(DIR_OBJ)/, $(SRCS:%.c=%.o))

# ----------------------------------
# Directories and Paths
# ----------------------------------

DIR_FT	=	./library/libft
DIR_INC	=	./includes
DIR_SRC	=	./sources
DIR_OBJ	=	./objs

SUBDIRS	=	builtins \
			error \
			parse \
			process \
			utils \
			variables

VPATH	=	$(DIR_SRC) $(addprefix $(DIR_SRC)/, $(SUBDIRS))

# ----------------------------------
# Compiler and flags
# ----------------------------------

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address
FTFLAG	=	-L$(DIR_FT) -lft

# ----------------------------------
# Rules
# ----------------------------------

all: $(NAME)

$(DIR_OBJ):
			@$(MKDIR) $@

$(DIR_OBJ)/%.o: %.c
			@$(ECHO) -n Compiling $(ORANGE)$< $(NOCOLOR)
			@$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@
			@$(ECHO) $(LINE_CLEAR)$(RETURN)Compiled $(BLUE)$< $(GREEN)Successfully$(NOCOLOR)

$(NAME):	$(DIR_FT)/$(FT) $(DIR_OBJ) $(OBJS)
			@$(ECHO) -n Making $(ORANGE)$(NAME)$(NOCOLOR) ...
			@$(CC) $(CFLAGS) -I$(DIR_INC) $(FTFLAG) $(OBJS) -o $(NAME)
			@$(ECHO) $(LINE_CLEAR)$(RETURN)Maked $(BLUE)$(NAME) $(GREEN)Successfully$(NOCOLOR)

$(DIR_FT)/$(FT):
			@$(ECHO) -n Summoning $(ORANGE)$(DIR_FT)/$(NOCOLOR)
			@make -C $(DIR_FT)
			@$(ECHO) $(LINE_CLEAR)$(RETURN)Summoned $(BLUE)$@ $(GREEN)Successfully$(NOCOLOR)

clean:
			@make -C $(DIR_FT) clean
			@$(ECHO) Clean up all object files of $(RED)$(FT)$(NOCOLOR)
			@$(RM) -r $(DIR_OBJ)
			@$(RM) -r $(DIR_OBJ)\ *
			@$(ECHO) Clean up all object files of $(RED)$(NAME)$(NOCOLOR)

fclean:		clean
			@make -C $(DIR_FT) fclean
			@$(ECHO) Removed $(RED)$(FT)$(NOCOLOR)
			@$(RM) -r $(NAME)
			@$(RM) -r *\ *
			@$(ECHO) Removed $(RED)$(NAME)$(NOCOLOR)

re:			fclean $(NAME)
