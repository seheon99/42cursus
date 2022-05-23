# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 14:14:55 by seyu              #+#    #+#              #
#    Updated: 2020/07/30 14:01:45 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTDIR=	libft
LIBFT	=	libft.a

SRCS	=	ft_printf.c \
			buffer/buffer_print.c \
			buffer/delete_buffer.c \
			buffer/new_buffer.c \
			holder/data_get_chartype.c \
			holder/data_get_inttype.c \
			holder/data_get_realtype.c \
			holder/data_set_chartype.c \
			holder/data_set_inttype.c \
			holder/data_set_realtype.c \
			holder/data_set_strtype.c \
			holder/delete_holder.c \
			holder/holder_data.c \
			holder/holder_flags.c \
			holder/holder_length.c \
			holder/holder_prec.c \
			holder/holder_type.c \
			holder/holder_width.c \
			holder/new_holder.c \
			holder/type_ischartype.c \
			holder/type_isinttype.c \
			holder/type_isrealtype.c \
			holder/type_isstrtype.c \
			holder/type_isvalid.c \
			write/chartype_datapart.c \
			write/chartype_filling.c \
			write/inttype_datapart.c \
			write/inttype_filling.c \
			write/inttype_prefixpart.c \
			write/strtype_datapart.c \
			write/strtype_filling.c \
			write/write_chartype.c \
			write/write_holder.c \
			write/write_inttype.c \
			write/write_nonholder.c \
			write/write_strtype.c
OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

MV		=	mv

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C $(LIBFTDIR) all
			mv $(LIBFTDIR)/$(LIBFT) $(NAME)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			make -C $(LIBFTDIR) clean
			$(RM) $(OBJS)

fclean:		clean
			make -C $(LIBFTDIR) fclean
			$(RM) $(NAME)

re:			fclean $(NAME)
