/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:05:27 by seyu              #+#    #+#             */
/*   Updated: 2020/07/25 19:05:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

long long	ft_llmax(long long n1, long long n2);
long long	ft_llmin(long long n1, long long n2);
long long	ft_llabs(long long n);

void		*ft_memset(void *s, int c, size_t size);
void		*ft_memcpy(void *dst, void *src, size_t size);
void		*ft_calloc(size_t nmemb, size_t size);

size_t		ft_strlen(const char *str);
void		*ft_strdup(const char *str);
int			ft_atoi(const char *nptr);
long		ft_strtol(const char *nptr,
					const char **endptr,
					int base);
long long	ft_strtoll(const char *nptr,
					const char **endptr,
					int base);
char		*ft_ulltostr(unsigned long long int numb,
					int prec,
					char *numstr,
					const char *base);

int			ft_wcslen(const wchar_t *str);

int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);

int			ft_convert_unicode_to_utf8(unsigned int unicode, char utf8[4]);

#endif
