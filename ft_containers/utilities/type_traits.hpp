/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:22:24 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 08:46:36 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_RAITS_HPP
# define TYPE_RAITS_HPP

namespace	ft
{

/* ---------------------------------------- */
/*              Helper Classes              */
/* ---------------------------------------- */

template <	typename T, T v >
struct	integral_constant
{
	typedef T					value_type;
	typedef integral_constant	type;

	static const T	value = v;

	operator value_type() const	{ return value; }
	const value_type	operator ()()const	{ return value; }
};

typedef integral_constant<bool, true>	true_type;
typedef integral_constant<bool, false>	false_type;

/* ---------------------------------------- */
/*         Primary Type Categories          */
/* ---------------------------------------- */

template <	typename T >
struct	is_void : false_type		{};

template <>
struct	is_void<void> : true_type	{};

template <	typename T >
struct	is_integral : false_type	{};

template <>
struct	is_integral<bool> : true_type	{};

template <>
struct	is_integral<char> : true_type	{};

template <>
struct	is_integral<short> : true_type	{};

template <>
struct	is_integral<int> : true_type	{};

template <>
struct	is_integral<long> : true_type	{};

template <>
struct	is_integral<unsigned char> : true_type	{};

template <>
struct	is_integral<unsigned short> : true_type	{};

template <>
struct	is_integral<unsigned int> : true_type	{};

template <>
struct	is_integral<unsigned long> : true_type	{};

template <	typename T >
struct	is_pointer : false_type		{};

template <	typename T >
struct	is_pointer<T*> : true_type	{};

/* ---------------------------------------- */
/*            Type Relationships            */
/* ---------------------------------------- */

template <	typename T1, typename T2 >
struct	is_same : false_type		{};

template <	typename T >
struct	is_same<T, T> : true_type	{};

namespace	detail
{

typedef	char	yes[1];
typedef char	no[2];

template <	typename Base, typename Derived >
struct	Host
{
	operator	Base*() const;
	operator	Derived*();
};

}

template <	typename Base, typename Derived >
struct	is_base_of
{
	template <	typename T >
	static detail::yes&	check(Derived*, T);
	static detail::no&	check(Base*, int);

	static const bool	value = sizeof(check(detail::Host<Base, Derived>(), int())) == sizeof(detail::yes);
};

/* ---------------------------------------- */
/*       Const-Volatillity Specifiers       */
/* ---------------------------------------- */

template <	typename T >
struct	remove_const				{ typedef T type; };

template <	typename T >
struct	remove_const<const T>		{ typedef T type; };

template <	typename T >
struct	remove_cv					{ typedef T type; };

template <	typename T >
struct	remove_cv<const T>			{ typedef T type; };

template <	typename T >
struct	remove_cv<volatile T>		{ typedef T type; };

template <	typename T >
struct	remove_cv<const volatile T>	{ typedef T type; };

template <	typename T >
struct	add_const	{ typedef const T type; };

/* ---------------------------------------- */
/*                References                */
/* ---------------------------------------- */

template <	typename T >
struct	remove_reference		{ typedef T type; };

template <	typename T >
struct	remove_reference<T&>	{ typedef T type; };

/* ---------------------------------------- */
/*      Miscellaneous Transformations       */
/* ---------------------------------------- */

template <	bool B >
struct	enable_if			{};

template <>
struct	enable_if<true>	{ typedef int type; };

template <	bool B, typename T, typename F >
struct	conditional	{ typedef T type; };

template <	typename T, typename F >
struct	conditional<false, T, F>	{ typedef F type; };

/* ---------------------------------------- */
/*           Supported Operations           */
/* ---------------------------------------- */

namespace	detail
{

template <	typename T, typename U >
struct	is_more_const : false_type {};

template <	typename T, typename U >
struct	is_more_const<const T, U> : true_type {};

template <	typename T, typename U >
struct	is_more_const<const T, const U> : false_type {};

template <	typename T, typename U >
struct	is_more_volatile : false_type {};

template <	typename T, typename U >
struct	is_more_volatile<volatile T, U> : true_type {};

template <	typename T, typename U >
struct	is_more_volatile<volatile T, volatile U> : false_type {};

template <	typename T, typename U >
struct	is_more_cv : conditional<is_more_const<T, U>::value && is_more_volatile<T, U>::value, true_type, false_type>::type {};

template <	typename T >
struct	is_default_constructible
{
	template <	typename U >
	static yes&	test(int(*)[sizeof(U())]);

	template <	typename U >
	static no&	test(...);

	static const bool	value = (sizeof(test<T>(0)) == sizeof(yes));
};

template <	typename T, typename Arg >
struct	is_constructible_1
{
	template <	typename U, typename Arg_ >
	static yes&	test(int(*)[sizeof(U(static_cast<Arg_>(*((typename remove_reference<Arg_>::type *)0))))]);

	template <	typename U, typename Arg_ >
	static no&	test(...);

	static const bool	value = (sizeof(test<T, Arg>(0)) == sizeof(yes));
};

template <	typename T, typename Arg >
struct	is_constructible_1<T*, Arg*>
	: conditional<
		is_void<typename remove_cv<T>::type>::value,
		true_type,
		typename conditional<
			is_void<typename remove_cv<T>::type>::value,
			false_type,
			typename conditional<
				is_more_cv<T, Arg>::value,
				false_type,
				is_base_of<T, Arg>
			>::type
		>::type
	>::type
{};

template <	typename T, typename Arg >
struct	is_constructible_1<T&, Arg&>
	: conditional<
		is_more_cv<T, Arg>::value,
		false_type,
		is_base_of<T, Arg>
	>::type
{};

template <	typename T, typename Arg1, typename Arg2 >
struct	is_constructible_2
{
	template <	typename U, typename Arg1_, typename Arg2_ >
	static yes&	test(int(*)[
		sizeof(U(
			static_cast<Arg1_>(*((typename remove_reference<Arg1_>::type *)0)),
			static_cast<Arg2_>(*((typename remove_reference<Arg2_>::type *)0))
		))
	]);

	template <	typename U, typename Arg1_, typename Arg2_ >
	static no&	test(...);

	static const bool	value = (sizeof(test<T, Arg1, Arg2>(0)) == sizeof(yes));
};

} // namespace detail

template <	typename T, typename Arg1 = void, typename Arg2 = void >
struct	is_constructible : conditional<detail::is_constructible_2<T, Arg1, Arg2>::value, true_type, false_type>::type
{};

template <	typename T, typename Arg >
struct	is_constructible<T, Arg> : conditional<detail::is_constructible_1<T, Arg>::value, true_type, false_type>::type
{};

template <	typename T >
struct	is_constructible<T> : conditional<detail::is_default_constructible<T>::value, true_type, false_type>::type
{};

}

#endif
