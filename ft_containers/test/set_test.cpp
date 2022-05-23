/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 02:40:53 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:17:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "test_macro.hpp"


#ifdef STL
# include <set>
# include <utility>
# include <functional>
# define NAMESPACE	std
#else
# include "set.hpp"
# include "utility.hpp"
# include "functional.hpp"
# define NAMESPACE	ft
#endif

template <	typename Key, typename T, typename Compare >
std::ostream&	operator<<(std::ostream& os, NAMESPACE::set<Key, T, Compare> container)
{
	typedef typename NAMESPACE::set<Key, T, Compare>::iterator			iterator;
	typedef typename NAMESPACE::set<Key, T, Compare>::reverse_iterator	reverse_iterator;

	os << "[ ";
	for (iterator itr = container.begin(); itr != container.end(); itr++)
		os << *itr << " ";
	os << "] [ ";
	for (reverse_iterator itr = container.rbegin(); itr != container.rend(); itr++)
		os << *itr << " ";
	os << "] " << container.size();
	return (os);
}

int main(void)
{
	typedef NAMESPACE::set<TEST_TYPE>			set_less;
	typedef NAMESPACE::set<TEST_TYPE, NAMESPACE::greater<TEST_TYPE> >
												set_more;
	typedef NAMESPACE::set<TEST_TYPE>::iterator	set_less_iter;
	typedef NAMESPACE::set<TEST_TYPE, NAMESPACE::greater<TEST_TYPE> >::iterator
												set_more_iter;

	/* ---------------------------------------- */
	/*               constructor                */
	/* ---------------------------------------- */
	PRINT("-----CONSTRUCTOR-----");

	set_less	set_one;

	EVAL(set_one = set_less());
	TEST(set_one.insert(0), set_one);
	TEST(set_one.insert(1), set_one);
	TEST(set_one.insert(2), set_one);
	TEST(set_one.insert(3), set_one);
	TEST(set_one.insert(4), set_one);
	TEST(set_one.insert(5), set_one);
	TEST(set_one.insert(6), set_one);
	TEST(set_one.insert(7), set_one);
	TEST(set_one.insert(8), set_one);
	TEST(set_one.insert(9), set_one);

	set_more	set_two;
	EVAL(set_two = set_more(set_one.begin(), set_one.end()));

	set_less	set_three;
	EVAL(set_three = set_less(set_one));

	set_more	map_four;
	EVAL(map_four = set_more(set_two));

	for (std::size_t i = 0; i < 5; i++)
	{
		TEST(set_two.erase(set_two.begin()), set_two);
	}
	EVAL(map_four = set_two);
	TEST(set_two.clear(), set_two);
	EVAL(map_four);

	/* ---------------------------------------- */
	/*                 Iterator                 */
	/* ---------------------------------------- */
	PRINT("-----ITERATOR-----");

	for (set_less::iterator itr = set_one.begin(); itr != set_one.end(); itr++)
		EVAL(*itr);

	/* ---------------------------------------- */
	/*                 Capacity                 */
	/* ---------------------------------------- */
	PRINT("-----CAPACITY-----");

	EVAL(set_one.size());
	EVAL(set_two.size());
	EVAL(set_three.size());
	EVAL(map_four.size());

	EVAL(set_one.max_size() * 0);

	/* ---------------------------------------- */
	/*                MODIFIERS                 */
	/* ---------------------------------------- */
	PRINT("-----MODIFIERS-----");

	EVAL(set_one);
	TEST(set_one.clear(), set_one);
	for (int i = 0; i < 10; i++)
	{
		NAMESPACE::pair<set_less_iter, bool>	rtn;

		rtn = set_one.insert(TEST_TYPE(i * 10 % 6));
		EVAL(*rtn.first);
		EVAL(*rtn.first);
		EVAL(rtn.second);
	}
	for (int i = 0; i < 10; i++)
	{
		set_more_iter	itr;

		itr = set_two.insert(set_two.end(), TEST_TYPE(i));
		PRINT(*itr);
	}
	EVAL(set_one);
	EVAL(set_three = set_less(set_one));
	for (int i = 0; i < 6; i++)
	{
		EVAL(set_one.erase(i));
		EVAL(set_one);
		EVAL(set_one.size());
	}
	TEST(set_two.erase(++++set_two.begin(), ------set_two.end()), set_two);
	TEST(set_two.erase(++set_two.begin()), set_two);
	EVAL(set_two.size());
	TEST(set_one.swap(set_three), set_one);
	EVAL(set_three);

	/* ---------------------------------------- */
	/*                  Lookup                  */
	/* ---------------------------------------- */
	PRINT("-----LOOKUP-----");

	set_one.clear();
	for (int i = 0; i < 20; i++)
		set_one.insert(TEST_TYPE(i * 3 + 1));
	EVAL(set_one);
	for (int i = 0; i < 20; i++)
		EVAL(set_one.count(TEST_TYPE(i)));
	for (int i = 0; i < 20; i++)
	{
		set_less_iter	itr;

		itr = set_one.find(TEST_TYPE(i));
		if (itr != set_one.end())
			PRINT("Found " << *itr);
		else
			PRINT("Cound not Found " << TEST_TYPE(i));
	}
	PRINT("EQUAL");
	for (int i = 0; i < 20; i++)
	{
		NAMESPACE::pair<set_less_iter, set_less_iter>	itr;

		itr = set_one.equal_range(i);
		if (itr.first != set_one.end())
		{
			for (set_less_iter i = itr.first; i != itr.second; i++)
				EVAL(*i);
		}
	}
	PRINT("LOWER");
	for (int i = 0; i < 20; i++)
	{
		set_less_iter	itr;

		itr = set_one.lower_bound(i);
		if (itr != set_one.end())
		{
			for (set_less_iter i = set_one.begin(); i != itr; i++)
				EVAL(*i);
			PRINT("");
		}
	}
	PRINT("UPPER");
	for (int i = 0; i < 20; i++)
	{
		set_less_iter	itr;

		itr = set_one.upper_bound(i);
		if (itr != set_one.begin())
		{
			for (set_less_iter i = set_one.begin(); i != itr; i++)
				EVAL(*i);
			PRINT("");
		}
	}
}
