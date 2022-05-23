# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 18:28:05 by seyu              #+#    #+#              #
#    Updated: 2021/05/24 12:39:22 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .c .o .h

CP		=	cp
RM		=	rm -f
MKDIR	=	mkdir -p
MV		=	mv
ECHO	=	/bin/echo

NAME	=	checker push_swap
NAME_FT	=	libft.a
NAME_CK	=	checker
NAME_PS	=	push_swap

USAGE_CK=	"./$(NAME_CK) <numbers>"
USAGE_PS=	"./$(NAME_PS) <numbers>"

# ----------------------------------
# Directories and Paths
# ----------------------------------

DIR_INC	=	./includes
DIR_SRC	=	./sources
DIR_OBJ =	./objects
DIR_FT	=	./libft

SUBDIRS	=	\
			data_structure \
			debug_tool \
			instruction \
			option \
			sort \
			sort/quick_sort \
			sort/special_sort \

VPATH	=	$(DIR_SRC) $(addprefix $(DIR_SRC)/, $(SUBDIRS))

# ----------------------------------
# Source files
# ----------------------------------

# Game rules
SRCS_BASE=	\
			game.c \
			base_instructions.c \
			print_instructions.c \
			is_sorted.c \

# Queue sources
SRCS_BASE+=	\
			queue_alloc.c \
			queue_compare.c \
			queue_instruction.c \
			queue_operator.c \
			queue_util.c \

# Stack sources
SRCS_BASE+=	\
			stack_alloc.c \
			stack_operator.c \
			stack_util.c \

SRCS_CK =	$(SRCS_BASE)
SRCS_CK	+=	\
			checker.c \

SRCS_PS =	$(SRCS_BASE)
SRCS_PS	+=	\
			push_swap.c \

# Compress instructions
SRCS_PS	+=	\
			compress_instructions.c \
			efficient_instructions.c \

# Debugging tools
SRCS_PS +=	\
			print_status.c \

# Special sorting sources
SRCS_PS	+=	\
			special_sort.c \
			answer_list.c \

# Quick sorting sources
SRCS_PS	+=	\
			util.c \
			quick_sort_util.c \
			quick_sort.c \
			special_quick_sort.c \

# ----------------------------------
# Object files
# ----------------------------------

OBJS_CK	=	$(addprefix $(DIR_OBJ)/, $(SRCS_CK:%.c=%.o))
OBJS_PS =	$(addprefix $(DIR_OBJ)/, $(SRCS_PS:%.c=%.o))

# ----------------------------------
# Compiler and flags
# ----------------------------------

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror

# ----------------------------------
# Echo Colors
# ----------------------------------

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
LINE_CLEAR	= $$'\33[2K\r'

# ----------------------------------
# Rules
# ----------------------------------

all:		$(DIR_FT)/$(NAME_FT) $(NAME_CK) $(NAME_PS)

$(DIR_OBJ):
	@$(MKDIR) $@

$(DIR_OBJ)/%.o:	%.c
	@$(ECHO) -n Compiling $(ORANGE)$<$(NOCOLOR) ...' '
	@$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@
	@$(ECHO) $(LINE_CLEAR)Compiled $(BLUE)$< $(GREEN)Successfully$(NOCOLOR)

$(DIR_FT)/$(NAME_FT):
	@$(ECHO) -n Summoning $(ORANGE)$(NAME_FT)$(NOCOLOR) ...' '
	@make -C $(DIR_FT) all
	@$(ECHO) $(LINE_CLEAR)Summoned $(BLUE)$@ $(GREEN)Successfully$(NOCOLOR)

$(NAME_CK):	$(DIR_FT)/$(NAME_FT) $(DIR_OBJ) $(OBJS_CK)
	@$(ECHO) ----------------------------------------
	@$(ECHO) -n Making $(ORANGE)$@$(NOCOLOR) ...' '
	@$(CC) $(CFLAGS) -I$(DIR_INC) $(OBJS_CK) -L$(DIR_FT) -lft -o $@
	@$(ECHO) -n $(LINE_CLEAR)Maked $(BLUE)$(NAME_CK) $(GREEN)Successfully$(NOCOLOR)
	@$(ECHO) ' ->' Usage: $(ORANGE)$(USAGE_CK)$(NOCOLOR)
	@$(ECHO) Compiled by $(ORANGE)$(CC)$(NOCOLOR) with $(ORANGE)$(CFLAGS)$(NOCOLOR) flags.
	@$(ECHO) ----------------------------------------

$(NAME_PS): $(DIR_FT)/$(NAME_FT) $(DIR_OBJ) $(OBJS_PS)
	@$(ECHO) ----------------------------------------
	@$(ECHO) -n Making $(ORANGE)$@$(NOCOLOR) ...' '
	@$(CC) $(CFLAGS) -I$(DIR_INC) $(OBJS_PS) -L$(DIR_FT) -lft -o $@
	@$(ECHO) -n $(LINE_CLEAR)Maked $(BLUE)$(NAME_PS) $(GREEN)Successfully$(NOCOLOR)
	@$(ECHO) ' ->' Usage: $(ORANGE)$(USAGE_PS)$(NOCOLOR)
	@$(ECHO) Compiled by $(ORANGE)$(CC)$(NOCOLOR) with $(ORANGE)$(CFLAGS)$(NOCOLOR) flags.
	@$(ECHO) ----------------------------------------

clean:
	@make -C $(DIR_FT) clean
	@$(ECHO) Clean up all object files of $(RED)$(NAME_FT)$(NOCOLOR)
	@$(RM) -r $(DIR_OBJ)
	@$(RM) *\ *
	@$(ECHO) Clean up all object files of $(RED)$(NAME_CK)$(NOCOLOR), $(RED)$(NAME_PS)$(NOCOLOR)

fclean:		clean
	@make -C $(DIR_FT) fclean
	@$(RM) -r $(NAME_CK) $(NAME_PS)
	@$(ECHO) Removed executable files: $(RED)$(NAME_CK)$(NOCOLOR), $(RED)$(NAME_PS)$(NOCOLOR)

re:			fclean all
