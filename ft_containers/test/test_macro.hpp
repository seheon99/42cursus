/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_macro.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:12:33 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:26:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MACRO_HPP
# define TEST_MACRO_HPP

# include <iostream>

# ifndef TEST_TYPE
#  define TEST_TYPE	int
# endif

# define PRINT(STR)				std::cout << STR << std::endl
# define TEST(CMD, PRINTVAR)	(void)(CMD);	PRINT(#CMD << ": " << (PRINTVAR))
# define EVAL(VAR)				PRINT(#VAR << ": " << (VAR))

# ifndef TEST_OPT_NUM
#  define TEST_OPT_NUM	1000000
# endif

#endif
