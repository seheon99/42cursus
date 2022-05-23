/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 02:40:53 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 08:47:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "test_macro.hpp"


#ifdef STL
# include <map>
# include <utility>
# include <functional>
# define NAMESPACE	std
#else
# include "map.hpp"
# include "utility.hpp"
# include "functional.hpp"
# define NAMESPACE	ft
#endif

template <	typename Key, typename T, typename Compare >
std::ostream&	operator<<(std::ostream& os, NAMESPACE::map<Key, T, Compare> container)
{
	typedef typename NAMESPACE::map<Key, T, Compare>::iterator			iterator;
	typedef typename NAMESPACE::map<Key, T, Compare>::reverse_iterator	reverse_iterator;

	os << "[ ";
	for (iterator itr = container.begin(); itr != container.end(); itr++)
		os << "(" << itr->first << ", " << itr->second << ") ";
	os << "] [ ";
	for (reverse_iterator itr = container.rbegin(); itr != container.rend(); itr++)
		os << "(" << itr->first << ", " << itr->second << ") ";
	os << "] " << container.size();
	return (os);
}

int main(void)
{
	typedef NAMESPACE::map<TEST_TYPE, int>				map_less;
	typedef NAMESPACE::map<TEST_TYPE, int, NAMESPACE::greater<TEST_TYPE> >
														map_more;
	typedef NAMESPACE::map<TEST_TYPE, int>::iterator	map_less_iter;
	typedef NAMESPACE::map<TEST_TYPE, int, NAMESPACE::greater<TEST_TYPE> >::iterator
														map_more_iter;

	/* ---------------------------------------- */
	/*               constructor                */
	/* ---------------------------------------- */
	PRINT("-----CONSTRUCTOR-----");

	map_less	map_one;

	EVAL(map_one = map_less());
	TEST(map_one.insert(NAMESPACE::make_pair(0, 0)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(1, 1)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(2, 2)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(3, 3)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(4, 4)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(5, 5)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(6, 6)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(7, 7)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(8, 8)), map_one);
	TEST(map_one.insert(NAMESPACE::make_pair(9, 9)), map_one);

	map_more	map_two;
	EVAL(map_two = map_more(map_one.begin(), map_one.end()));

	map_less	map_three;
	EVAL(map_three = map_less(map_one));

	map_more	map_four;
	EVAL(map_four = map_more(map_two));

	for (std::size_t i = 0; i < 5; i++)
	{
		TEST(map_two.erase(map_two.begin()), map_two);
	}
	EVAL(map_four = map_two);
	TEST(map_two.clear(), map_two);
	EVAL(map_four);

	/* ---------------------------------------- */
	/*              Element Access              */
	/* ---------------------------------------- */
	PRINT("-----ELEMENT-ACCESS-----");

	map_one.clear();
	for (int i = 0; i < 20; i++)
		map_one.insert(NAMESPACE::make_pair(i * 4 % 15 + i * 3 % 12, 42));

	EVAL(map_one);
	for (int i = 0; i < 20; i++)
		EVAL(map_one.at(i * 4 % 15 + i * 3 % 12));
	for (int i = 0; i < 20; i++)
		EVAL(map_one.at(i * 4 % 15 + i * 3 % 12));
	for (int i = 0; i < 27; i++)
	{
		try
		{
			PRINT("map_one[" << i << "] is " << map_one.at(i));
		}
		catch (const std::exception& e)
		{
			PRINT("map_one does not have the key " << i);
		}
	}
	for (int i = 0; i < 27; i++)
		EVAL(map_one[i] = i * 2);
	for (int i = 0; i < 27; i++)
	{
		try
		{
			PRINT("map_one[" << i << "] is " << map_one.at(i));
		}
		catch (const std::exception& e)
		{
			PRINT("map_one does not have the key " << i);
		}
	}

	/* ---------------------------------------- */
	/*                 Iterator                 */
	/* ---------------------------------------- */
	PRINT("-----ITERATOR-----");

	for (map_less::iterator itr = map_one.begin(); itr != map_one.end(); itr++)
		itr->second = 42;

	/* ---------------------------------------- */
	/*                 Capacity                 */
	/* ---------------------------------------- */
	PRINT("-----CAPACITY-----");

	EVAL(map_one.size());
	EVAL(map_two.size());
	EVAL(map_three.size());
	EVAL(map_four.size());

	EVAL(map_one.max_size() * 0);

	/* ---------------------------------------- */
	/*                MODIFIERS                 */
	/* ---------------------------------------- */
	PRINT("-----MODIFIERS-----");

	EVAL(map_one);
	TEST(map_one.clear(), map_one);
	for (int i = 0; i < 10; i++)
	{
		NAMESPACE::pair<map_less_iter, bool>	rtn;

		rtn = map_one.insert(NAMESPACE::make_pair(TEST_TYPE(i * 10 % 6), i * 4 % 11));
		EVAL(rtn.first->first);
		EVAL(rtn.first->second);
		EVAL(rtn.second);
	}
	for (int i = 0; i < 10; i++)
	{
		map_more_iter	itr;

		itr = map_two.insert(map_two.end(), NAMESPACE::make_pair(TEST_TYPE(i), i * 10));
		PRINT(itr->first << ", " << itr->second);
	}
	EVAL(map_one);
	EVAL(map_three = map_less(map_one));
	for (int i = 0; i < 6; i++)
	{
		EVAL(map_one.erase(i));
		EVAL(map_one);
		EVAL(map_one.size());
	}
	TEST(map_two.erase(++++map_two.begin(), ------map_two.end()), map_two);
	TEST(map_two.erase(++map_two.begin()), map_two);
	EVAL(map_two.size());
	TEST(map_one.swap(map_three), map_one);
	EVAL(map_three);

	/* ---------------------------------------- */
	/*                  Lookup                  */
	/* ---------------------------------------- */
	PRINT("-----LOOKUP-----");

	map_one.clear();
	for (int i = 0; i < 20; i++)
		map_one.insert(NAMESPACE::make_pair(TEST_TYPE(i * 3 + 1), i * 10));
	EVAL(map_one);
	for (int i = 0; i < 20; i++)
		EVAL(map_one.count(TEST_TYPE(i)));
	for (int i = 0; i < 20; i++)
	{
		map_less_iter	itr;

		itr = map_one.find(TEST_TYPE(i));
		if (itr != map_one.end())
			PRINT("Found " << itr->first);
		else
			PRINT("Cound not Found " << TEST_TYPE(i));
	}
	PRINT("EQUAL");
	for (int i = 0; i < 20; i++)
	{
		NAMESPACE::pair<map_less_iter, map_less_iter>	itr;

		itr = map_one.equal_range(i);
		if (itr.first != map_one.end())
		{
			for (map_less_iter i = itr.first; i != itr.second; i++)
				EVAL(i->second);
		}
	}
	PRINT("LOWER");
	for (int i = 0; i < 20; i++)
	{
		map_less_iter	itr;

		itr = map_one.lower_bound(i);
		if (itr != map_one.end())
		{
			for (map_less_iter i = map_one.begin(); i != itr; i++)
				EVAL(i->second);
			PRINT("");
		}
	}
	PRINT("UPPER");
	for (int i = 0; i < 20; i++)
	{
		map_less_iter	itr;

		itr = map_one.upper_bound(i);
		if (itr != map_one.begin())
		{
			for (map_less_iter i = map_one.begin(); i != itr; i++)
				EVAL(i->second);
			PRINT("");
		}
	}
}
