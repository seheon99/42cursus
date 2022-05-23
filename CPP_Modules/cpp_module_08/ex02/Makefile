# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 23:07:12 by seyu              #+#    #+#              #
#    Updated: 2021/04/15 06:07:17 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)

.SUFFIXES:
.SUFFIXES: .cpp .o .hpp

NAME	=	prove.out

CP		=	cp
RM		=	rm -f
MKDIR	=	mkdir -p
MV		=	mv

ifeq ($(UNAME_S),Linux)
ECHO	=	/bin/echo -e
else
ECHO	=	/bin/echo
endif

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
			MutantStack.cpp

# ----------------------------------
# Compiler and flags
# ----------------------------------

ifeq ($(UNAME_S),Linux)
CC	=	g++
else
CC	=	clang++
endif
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
CLIBS	=

# ----------------------------------
# Echo Colors
# ----------------------------------


ifeq ($(UNAME_S),Linux)
NOCOLOR		= '\033[0m'
RED			= '\033[0;31m'
GREEN		= '\033[0;32m'
ORANGE		= '\033[0;33m'
BLUE		= '\033[0;34m'
PURPLE		= '\033[0;35m'
CYAN		= '\033[0;36m'
LIGHTGRAY	= '\033[0;37m'
DARKGRAY	= '\033[1;30m'
LIGHTRED	= '\033[1;31m'
LIGHTGREEN	= '\033[1;32m'
YELLOW		= '\033[1;33m'
LIGHTBLUE	= '\033[1;34m'
LIGHTPURPLE	= '\033[1;35m'
LIGHTCYAN	= '\033[1;36m'
WHITE		= '\033[1;37m'
else
NOCOLOR		= $$'\033[0m'
RED			= $$'\033[0;31m'
GREEN		= $$'\033[0;32m'
ORANGE		= $$'\033[0;33m'
BLUE		= $$'\033[0;34m'
PURPLE		= $$'\033[0;35m'
CYAN		= $$'\033[0;36m'
LIGHTGRAY	= $$'\033[0;37m'
DARKGRAY	= $$'\033[1;30m'
LIGHTRED	= $$'\033[1;31m'
LIGHTGREEN	= $$'\033[1;32m'
YELLOW		= $$'\033[1;33m'
LIGHTBLUE	= $$'\033[1;34m'
LIGHTPURPLE	= $$'\033[1;35m'
LIGHTCYAN	= $$'\033[1;36m'
WHITE		= $$'\033[1;37m'
endif

# ----------------------------------
# Echo Escape Characters
# ----------------------------------

ifeq ($(UNAME_S),Linux)
LINE_CLEAR	= '\33[2K\r'
else
LINE_CLEAR	= $$'\33[2K\r'
endif

# ----------------------------------
# Rules
# ----------------------------------

all: $(NAME)

$(NAME):	$(SRCS)
			@$(ECHO) -n Compiling $(ORANGE)$(NAME)$(NOCOLOR) ...
			@$(CC) $(CFLAGS) $(CLIBS) -I$(DIR_INC) $(SRCS) -o $(NAME)
			@$(ECHO) -n $(LINE_CLEAR)Compiled sources $(GREEN)Successfully$(NOCOLOR) by $(ORANGE)$(CC)$(NOCOLOR) compiler with $(ORANGE)$(CFLAGS)$(NOCOLOR) flags:
ifeq ($(UNAME_S),Linux)
			@$(ECHO) $(addprefix '\n'    $(GREEN)✔$(NOCOLOR) , $(SRCS))
else
			@$(ECHO) $(addprefix $$'\n'    $(GREEN)✔$(NOCOLOR) , $(SRCS))
endif
			@$(ECHO) You can execute $(BLUE)$(NAME)$(NOCOLOR) file.

clean:

fclean:		clean
			@$(RM) -r $(NAME)
			@$(ECHO) Removed $(RED)$(NAME)$(NOCOLOR)

re:			fclean $(NAME)
