/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 02:40:53 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 05:29:03 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "test_macro.hpp"


#ifdef STL
# include <stack>
# define NAMESPACE	std
#else
# include "stack.hpp"
# define NAMESPACE	ft
#endif

template <	typename T, typename Container >
std::ostream&	operator<<(std::ostream& os, NAMESPACE::stack<T, Container> container)
{
	os << container.size() << "[ ";
	for (; container.size() > 0; container.pop())
		os << container.top() << " ";
	os << "]";
	return (os);
}

int main(void)
{
	typedef NAMESPACE::stack<TEST_TYPE>	stack;

	/* ---------------------------------------- */
	/*               Constructor                */
	/* ---------------------------------------- */
	stack	stack_one;
	stack	stack_two;

	EVAL(stack_one = stack());

	for (int i = 0; i < 10; i++)
	{
		TEST(stack_one.push(TEST_TYPE((i * 8 + 2) % 6)), stack_one);
	}

	EVAL(stack_two = stack(stack_one));

	/* ---------------------------------------- */
	/*                operator=                 */
	/* ---------------------------------------- */
	stack	stack_three;

	EVAL(stack_three = stack_two);
	TEST(stack_two.pop(), stack_two);
	EVAL(stack_three);

	/* ---------------------------------------- */
	/*                  empty                   */
	/* ---------------------------------------- */

	for (stack stack_itr = stack_one; stack_itr.empty() == false; stack_itr.pop())
	{
		EVAL(stack_itr.top());
	}

	/* ---------------------------------------- */
	/*          Comparison Operations           */
	/* ---------------------------------------- */

	stack	stack_four;

	EVAL(stack_four = stack_three);
	EVAL(stack_three == stack_four);
	EVAL(stack_three != stack_four);
	EVAL(stack_three < stack_four);
	EVAL(stack_three <= stack_four);
	EVAL(stack_three > stack_four);
	EVAL(stack_three >= stack_four);
	TEST(stack_four.pop(), stack_four);
	EVAL(stack_three == stack_four);
	EVAL(stack_three != stack_four);
	EVAL(stack_three < stack_four);
	EVAL(stack_three <= stack_four);
	EVAL(stack_three > stack_four);
	EVAL(stack_three >= stack_four);
}
