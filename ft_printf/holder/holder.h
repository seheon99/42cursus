/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:34:18 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 18:08:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOLDER_H
# define HOLDER_H

# include <wchar.h>
# include <stdarg.h>

# define NOFLAGS	0
# define FLAG_HASH	1
# define FLAG_MINUS	2
# define FLAG_ZERO	4
# define FLAG_BLANK	8
# define FLAG_PLUS	16

# define NOLENGTH	0
# define LENGTH_HH	1
# define LENGTH_H	2
# define LENGTH_L	3
# define LENGTH_LL	4

struct		s_holder
{
	int		flags;
	int		width;
	int		prec;
	int		length;
	int		type;
	void	*data;
};
typedef	struct s_holder	t_holder;

t_holder	*new_holder(const char *format,
					va_list *ap,
					ssize_t *bytes_read);
void		delete_holder(t_holder **holder);

int			holder_flags(const char *flagspart, int *flags);
int			holder_width(const char *widthpart, int *width, va_list *ap);
int			holder_prec(const char *precpart, int *prec, va_list *ap);
int			holder_length(const char *lengthpart, int *length);
int			holder_type(const char *typepart, int *type);
void		*holder_data(va_list *ap, int length, int type);

int			type_isvalid(const int type);
int			type_isinttype(const int type);
int			type_isrealtype(const int type);
int			type_ischartype(const int type);
int			type_isstrtype(const int type);

void		*data_set_inttype(va_list *ap, int length);
void		*data_set_realtype(va_list *ap);
void		*data_set_chartype(va_list *ap, int length);
void		*data_set_strtype(va_list *ap, int length);
size_t		data_get_inttype(t_holder *holder);
double		data_get_realtype(t_holder *holder);
wint_t		data_get_chartype(t_holder *holder);

#endif
