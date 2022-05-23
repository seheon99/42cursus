# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 23:07:12 by seyu              #+#    #+#              #
#    Updated: 2021/04/04 05:06:13 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .cpp .o .hpp

NAME	=	simulation

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
DIR_OBJ	=	./objs

SUBDIRS	=

VPATH	=	$(DIR_SRC) $(addprefix $(DIR_SRC)/, $(SUBDIRS))

# ----------------------------------
# Mandatory source files
# ----------------------------------

# Main source file

SRCS	=	main.cpp

SRCS	+=	\
			ClapTrap.cpp \
			FragTrap.cpp \
			ScavTrap.cpp

# ----------------------------------
# Object files
# ----------------------------------

OBJS	=	$(addprefix $(DIR_OBJ)/, $(SRCS:%.cpp=%.o))

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

$(DIR_OBJ):
			@$(MKDIR) $@

$(DIR_OBJ)/%.o: %.cpp
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
			@$(RM) -r *.replace
			@$(RM) -r *\ *
			@$(ECHO) Removed $(RED)$(NAME)$(NOCOLOR)

re:			fclean $(NAME)
