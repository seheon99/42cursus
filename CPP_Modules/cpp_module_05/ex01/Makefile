# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 23:07:12 by seyu              #+#    #+#              #
#    Updated: 2021/04/11 03:19:52 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .cpp .o .hpp

NAME	=	work.out

CP		=	cp
RM		=	rm -f
MKDIR	=	mkdir -p
MV		=	mv
ECHO	=	/bin/echo

# ----------------------------------
# Directories and Paths
# ----------------------------------

DIR_INC	=	./
DIR_SRC	=	./

SUBDIRS	=

VPATH	=	$(DIR_SRC) $(addprefix $(DIR_SRC)/, $(SUBDIRS))

# ----------------------------------
# Mandatory source files
# ----------------------------------

# Main source file

SRCS	=	main.cpp

SRCS	+=	\
			Bureaucrat.cpp \
			Form.cpp

# ----------------------------------
# Compiler and flags
# ----------------------------------

CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
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

$(NAME):	$(SRCS)
			@$(ECHO) -n Compiling $(ORANGE)$(NAME)$(NOCOLOR) ...
			@$(CC) $(CFLAGS) $(CLIBS) -I$(DIR_INC) $(SRCS) -o $(NAME)
			@$(ECHO) -n $(LINE_CLEAR)Compiled sources $(GREEN)Successfully$(NOCOLOR) by $(ORANGE)$(CC)$(NOCOLOR) compiler with $(ORANGE)$(CFLAGS)$(NOCOLOR) flags:
			@$(ECHO) $(addprefix $$'\n'    $(GREEN)✔$(NOCOLOR) , $(SRCS))
			@$(ECHO) You can execute $(BLUE)$(NAME)$(NOCOLOR) file.

clean:

fclean:		clean
			@$(RM) -r $(NAME)
			@$(ECHO) Removed $(RED)$(NAME)$(NOCOLOR)

re:			fclean $(NAME)
