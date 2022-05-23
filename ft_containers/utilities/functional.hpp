/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 01:43:09 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 19:19:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace	ft
{

/* ---------------------------------------- */
/*               Base Classes               */
/* ---------------------------------------- */

template <typename arg, typename result>
struct unary_function
{
	typedef arg argument_type;
	typedef result result_type;
};

template <typename arg1, typename arg2, typename result>
struct binary_function
{
	typedef arg1 first_argument_type;
	typedef arg2 second_argument_type;
	typedef result result_type;
};

/* ---------------------------------------- */
/*             Operator Classes             */
/* ---------------------------------------- */

/* Arithmetic Operations */

template <typename T>
struct plus : binary_function<T, T, T>
{
	T operator() (const T& x, const T& y) const { return (x + y); }
};

template <typename T>
struct minus : binary_function<T, T, T>
{
	T operator() (const T& x, const T& y) const { return (x - y); }
};

template <typename T>
struct multiplies : binary_function<T, T, T>
{
	T operator() (const T& x, const T& y) const { return (x * y); }
};

template <typename T>
struct divides : binary_function<T, T, T>
{
	T operator() (const T& x, const T& y) const { return (x / y); }
};

template <typename T>
struct modulus : binary_function<T, T, T>
{
	T operator() (const T& x, const T& y) const { return (x % y); }
};

template <typename T>
struct negate : unary_function<T, T>
{
	T operator() (const T& x) const { return (-x); }
};

/* Comparison Operations */

template <typename T>
struct equal_to : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x == y); }
};

template <typename T>
struct not_equal_to : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x != y); }
};

template <typename T>
struct greater : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x > y); }
};

template <typename T>
struct less : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x < y); }
};

template <typename T>
struct greater_equal : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x >= y); }
};

template <typename T>
struct less_equal : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x <= y); }
};

/* Logical Operations */

template <typename T>
struct logical_and : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x && y); }
};

template <typename T>
struct logical_or : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const { return (x || y); }
};

template <typename T>
struct logical_not : unary_function<T, bool>
{
	bool operator() (const T& x) const { return (!x); }
};

}

#endif
