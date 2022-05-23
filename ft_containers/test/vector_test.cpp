/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:12:08 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 08:52:23 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "test_macro.hpp"

#ifdef STL
# include <vector>
namespace ft = std;
#else
# include "vector.hpp"
#endif

template <	typename T >
std::ostream&	operator<<(std::ostream& os, ft::vector<T> container)
{
	typedef typename ft::vector<T>::iterator			iterator;
	typedef typename ft::vector<T>::reverse_iterator	reverse_iterator;

	os << "[ ";
	for (iterator itr = container.begin(); itr != container.end(); itr++)
		os << *itr << " ";
	os << "] [ ";
	for (reverse_iterator itr = container.rbegin(); itr != container.rend(); itr++)
		os << *itr << " ";
	os << "]";
	return (os);
}

int main(void)
{
	typedef ft::vector<int>			vector_int;
	typedef	vector_int::iterator			iterator_int;
	typedef ft::vector<double>		vector_double;
	typedef	vector_double::iterator			iterator_double;
	typedef ft::vector<std::string>	vector_string;
	typedef	vector_string::iterator			iterator_string;

	iterator_int	intitr;
	iterator_double	doubleitr;
	iterator_string	stringitr;

	/* ---------------------------------------- */
	/*               constructor                */
	/* ---------------------------------------- */
	PRINT("-----CONSTRUCTOR-----");

	vector_int	vec_one;
	vector_int	vec_two;
	vector_int	vec_three;
	vector_int	vec_four;

	TEST(vec_one = vector_int(10), vec_one);
	TEST(vec_two = vector_int(4, 42), vec_two);
	TEST(vec_three = vector_int(vec_one.begin(), vec_one.end()), vec_three);
	TEST(vec_four = vector_int(vec_two), vec_four);

	/* ---------------------------------------- */
	/*                operator=                 */
	/* ---------------------------------------- */
	PRINT("-----OPERATOR=-----");

	TEST(vec_one = vec_two, vec_one);

	vector_string	vec_string_one;
	vector_string	vec_string_two;
	vector_string	vec_string_three;
	vector_string	vec_string_four;

	TEST(vec_string_one = vector_string(1, "ONE"), vec_string_one);
	TEST(vec_string_two = vector_string(4, "TWO"), vec_string_two);
	TEST(vec_string_three = vector_string(3, "THREE"), vec_string_three);
	TEST(vec_string_four = vector_string(2, "FOUR"), vec_string_four);

	TEST(vec_string_one = vec_string_three, vec_string_one);
	TEST(vec_string_two = vec_string_four, vec_string_two);
	TEST(vec_string_three = vec_string_one, vec_string_three);
	TEST(vec_string_one.clear(), vec_string_one);
	TEST("vec_string_three AFTER CLEAR vec_string_one", vec_string_three);

	/* ---------------------------------------- */
	/*                  assign                  */
	/* ---------------------------------------- */
	PRINT("-----assign-----");

	TEST(vec_one.assign(6, 42), vec_one);
	for (size_t i = 0; i < 11; i++)
		vec_one.push_back(i * 10);
	TEST("Initialized vec_one", vec_one);
	TEST(vec_three.assign(vec_one.begin(), vec_one.end()), vec_three);
	TEST(vec_four.assign(vec_one.begin() + 2, vec_one.end() - 1), vec_four);
	TEST(vec_string_one.assign(2, "Hello, World!"), vec_string_one);
	for (size_t i = 0; i < 10; i++)
		vec_string_three.push_back(std::string(i, i + 'a'));
	TEST("Initialized vec_string_three", vec_string_three);
	TEST(vec_string_four.assign(vec_string_three.begin() + 2, vec_string_three.end() - 4), vec_string_four);

	/* ---------------------------------------- */
	/*                    at                    */
	/* ---------------------------------------- */
	PRINT("-----at-----");

	TEST(vec_one = vector_int(7), vec_one);
	for (size_t i = 0; i < vec_one.size(); i++)
		TEST(vec_one.at(i) = (vec_one.size() - i) * 3, vec_one);

	vector_int const vec_const_one = vector_int(vec_one);

	TEST("vec_const_one = vector_int(vec_one)", vec_const_one);

	try
	{
		TEST(vec_one.at(10) = 42, vec_one);
	}
	catch(const std::out_of_range& e)
	{
		PRINT("vec_one.at(10): std::out_of_range");
	}
	catch(const std::exception& e)
	{
		PRINT("vec_one.at(10): std::exception");
	}

	/* ---------------------------------------- */
	/*                operator[]                */
	/* ---------------------------------------- */
	PRINT("-----operator[]-----");

	for (size_t i = 0; i < vec_one.size(); i++)
		TEST(std::cout << vec_one[i] << std::endl, vec_one);
	for (size_t i = 0; i < vec_const_one.size(); i++)
		TEST(std::cout << vec_const_one[i] << std::endl, vec_one);

	/* ---------------------------------------- */
	/*               front, back                */
	/* ---------------------------------------- */
	PRINT("-----front, back-----");

	TEST(vec_one.front(), vec_one.front());
	TEST(vec_const_one.front(), vec_const_one.front());
	TEST(vec_one.back(), vec_one.back());
	TEST(vec_const_one.back(), vec_const_one.back());

	/* ---------------------------------------- */
	/*                 iterator                 */
	/* ---------------------------------------- */
	PRINT("-----iterator-----");

	for (vector_int::iterator itr = vec_one.begin(); itr != vec_one.end(); itr++)
		*itr = 42;

	/* ---------------------------------------- */
	/*                  empty                   */
	/* ---------------------------------------- */
	PRINT("-----empty-----");

	TEST(vec_one.empty(), vec_one.empty());
	TEST(vec_one.clear(), vec_one);
	TEST(vec_one.empty(), vec_one.empty());

	/* ---------------------------------------- */
	/*                  insert                  */
	/* ---------------------------------------- */
	PRINT("-----insert-----");

	TEST(vec_one = vector_int(10), vec_one);
	for (size_t i = 0; i < vec_one.size(); i++)
		vec_one[i] = (vec_one.size() - i) * 3;
	TEST("Initialized vec_one", vec_one);
	TEST(vec_two = vector_int(), vec_two);
	TEST(vec_two.insert(vec_two.end(), 42), vec_two);
	TEST(vec_two.insert(vec_two.begin(), 2, 21), vec_two);
	TEST(vec_two.insert(vec_two.end() - 2, 42), vec_two);
	TEST(vec_two.insert(vec_two.end(), 2, 84), vec_two);
	TEST(vec_two.resize(4), vec_two);
	TEST(vec_two.insert(vec_two.begin() + 2, vec_one.begin(), vec_one.end()), vec_two);
	TEST(vec_two = vector_int(), vec_two);
	TEST(vec_two.insert(vec_two.begin(), vec_one.begin(), vec_one.begin() + 3), vec_two);
	TEST(vec_two.insert(vec_two.begin(), vec_one.begin() + 3, vec_one.end()), vec_two);
	TEST(vec_two.insert(vec_two.end(), vec_one.begin(), vec_one.begin() + 3), vec_two);
	TEST("*vec_two.insert(vec_two.end(), 42)", *vec_two.insert(vec_two.end(), 42));
	TEST("*vec_two.insert(vec_two.begin() + 5, 84)", *vec_two.insert(vec_two.begin() + 5, 84));
	TEST(vec_two, vec_two);

	/* ---------------------------------------- */
	/*                  erase                   */
	/* ---------------------------------------- */
	PRINT("-----erase-----");

	TEST(vec_string_one = vector_string(10), vec_string_one);

	for (size_t i = 0; i < 10; i++)
	{
		TEST(vec_string_one[i] = std::string((vec_string_one.size() - i), i + 'A'), vec_string_one[i]);
	}
	PRINT(vec_string_one);
	TEST(vec_string_one.erase(vec_string_one.begin() + 2), vec_string_one);
	TEST(vec_string_one.erase(vec_string_one.begin()), vec_string_one);
	TEST(vec_string_one.erase(vec_string_one.end() - 1), vec_string_one);
	TEST(vec_string_one.erase(vec_string_one.begin(), vec_string_one.begin() + 3), vec_string_one);
	TEST(vec_string_one.erase(vec_string_one.end() - 3, vec_string_one.end() - 1), vec_string_one);
	TEST(vec_string_one.push_back("Hello"), vec_string_one);
	TEST(vec_string_one.push_back("Hi there"), vec_string_one);
	TEST(vec_string_one.erase(vec_string_one.end() - 3, vec_string_one.end()), vec_string_one);
	TEST(vec_string_one.push_back("ONE"), vec_string_one);
	TEST(vec_string_one.push_back("TWO"), vec_string_one);
	TEST(vec_string_one.push_back("THREE"), vec_string_one);
	TEST(vec_string_one.push_back("FOUR"), vec_string_one);
	TEST(vec_string_one.erase(vec_string_one.begin(), vec_string_one.end()), vec_string_one);

	/* ---------------------------------------- */
	/*           push_back, pop_back            */
	/* ---------------------------------------- */
	PRINT("-----push_back, pop_back-----");

	TEST(vec_string_one = vector_string(8), vec_string_one);
	TEST(vec_string_two = vector_string(), vec_string_two);

	stringitr = vec_string_one.begin();
	for (size_t i = 0; i < vec_string_one.size(); i++)
	{
		TEST(stringitr[i] = std::string((vec_string_one.size() - i), i + 'A'), stringitr[i]);
	}
	TEST(vec_string_one.push_back("One long string"), vec_string_one);
	TEST(vec_string_two.push_back("Another long string"), vec_string_two);
	TEST(vec_string_one.pop_back(), vec_string_one);
	TEST(vec_string_two.pop_back(), vec_string_two);

	/* ---------------------------------------- */
	/*                  resize                  */
	/* ---------------------------------------- */
	PRINT("-----resize-----");

	vector_double	vec_double_one;
	vector_double	vec_double_two;

	TEST(vec_double_one = vector_double(10, 4.2), vec_double_one);
	TEST(vec_double_two = vector_double(5, 2.1), vec_double_one);
	TEST(vec_double_one.resize(5, 2.1), vec_double_one);
	TEST(vec_double_one.resize(10), vec_double_one);
	TEST(vec_double_two.resize(10, 4.2), vec_double_two);
	TEST(vec_double_one.assign(0, 0), vec_double_one);
	TEST(vec_double_one.resize(10, 2.4), vec_double_one);
	TEST(vec_double_one.resize(0), vec_double_one);

	/* ---------------------------------------- */
	/*      iterator arithmetic operators       */
	/* ---------------------------------------- */
	PRINT("-----iterator arithmetic operators-----");

	TEST(vec_string_one = vector_string(10), vec_string_one);
	stringitr = vec_string_one.begin();
	for (size_t i = 0; i < vec_string_one.size(); i++)
	{
		TEST(stringitr[i] = std::string((vec_string_one.size() - i), i + 'A'), stringitr[i]);
	}
	TEST(*((stringitr += 4) + 2) = std::string("One short string"), vec_string_one);
	EVAL(*(stringitr + 2));
	EVAL(*(2 + stringitr));
	EVAL(vec_string_one.end() - stringitr);
	EVAL(*(stringitr - 4));
	EVAL(*((stringitr -= 4) + 6));

	/* ---------------------------------------- */
	/*      iterator comparative operators      */
	/* ---------------------------------------- */
	PRINT("-----iterator comparative operators-----");

	iterator_string	stringitr_two;

	EVAL(vec_string_one);
	TEST(stringitr = vec_string_one.begin(), *stringitr);
	TEST(stringitr_two = vec_string_one.begin() + 4, *stringitr_two);
	EVAL(stringitr < stringitr_two);
	EVAL(stringitr <= stringitr_two);
	EVAL(stringitr > stringitr_two);
	EVAL(stringitr >= stringitr_two);
	EVAL(stringitr_two < stringitr);
	EVAL(stringitr_two <= stringitr);
	EVAL(stringitr_two > stringitr);
	EVAL(stringitr_two >= stringitr);

	TEST(stringitr = stringitr_two, *stringitr);
	EVAL(stringitr < stringitr_two);
	EVAL(stringitr <= stringitr_two);
	EVAL(stringitr > stringitr_two);
	EVAL(stringitr >= stringitr_two);
	EVAL(stringitr_two < stringitr);
	EVAL(stringitr_two <= stringitr);
	EVAL(stringitr_two > stringitr);
	EVAL(stringitr_two >= stringitr);

	EVAL(stringitr < vec_string_one.end());
	EVAL(stringitr <= vec_string_one.end());
	EVAL(stringitr > vec_string_one.end());
	EVAL(stringitr >= vec_string_one.end());
	EVAL(vec_string_one.end() < stringitr);
	EVAL(vec_string_one.end() <= stringitr);
	EVAL(vec_string_one.end() > stringitr);
	EVAL(vec_string_one.end() >= stringitr);

	EVAL(vec_string_one.begin() < stringitr_two);
	EVAL(vec_string_one.begin() <= stringitr_two);
	EVAL(vec_string_one.begin() > stringitr_two);
	EVAL(vec_string_one.begin() >= stringitr_two);
	EVAL(stringitr_two < vec_string_one.begin());
	EVAL(stringitr_two <= vec_string_one.begin());
	EVAL(stringitr_two > vec_string_one.begin());
	EVAL(stringitr_two >= vec_string_one.begin());

	TEST(stringitr++, *stringitr);
	EVAL(*stringitr++);
	EVAL(*stringitr);

	/* ---------------------------------------- */
	/*           iterator operator[]            */
	/* ---------------------------------------- */
	PRINT("-----iterator operator[]-----");

	TEST(vec_one = vector_int(5, 4), vec_one);
	intitr = vec_one.begin();
	for (size_t i = 0; i < vec_one.size(); i++)
		intitr[i] = i * 21;
	TEST("Initialized vec_one", vec_one);

	return (0);
}
