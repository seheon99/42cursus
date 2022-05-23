/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:57:31 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 02:23:46 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace	ft
{

template <	typename T1, typename T2 >
struct	pair
{
	/* ---------------------------------------- */
	/*               Member Types               */
	/* ---------------------------------------- */

	typedef	T1	first_type;
	typedef	T2	second_type;

	/* ---------------------------------------- */
	/*             Member functions             */
	/* ---------------------------------------- */

	/*	Constructor */

	pair() : first(T1()), second(T2()) {}
	pair(const T1& x, const T2& y) : first(x), second(y) {}

	template <	typename U1, typename U2 >
	pair(const pair<U1, U2>& p) : first(T1(p.first)), second(T2(p.second)) {}

	pair(const pair& p) : first(T1(p.first)), second(T2(p.second)) {}

	/*	Destructor */

	~pair() {}

	/*	Operator */

	pair& operator=(pair const& other)
	{
		if (this != &other)
		{
			first = other.first;
			second = other.second;
		}
		return *this;
	}

	/* ---------------------------------------- */
	/*              Member Objects              */
	/* ---------------------------------------- */

	T1 first;
	T2 second;
};

/* ---------------------------------------- */
/*           Non-member functions           */
/* ---------------------------------------- */

template <	typename T1, typename T2 >
pair<T1, T2> make_pair(T1 t, T2 u)
{
	return pair<T1, T2>(t, u);
}

template <	typename T1, typename T2 >
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <	typename T1, typename T2 >
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return !(lhs == rhs);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
	return (lhs.first < rhs.first) ||
			(lhs.first == rhs.first && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
	return !(rhs < lhs);
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
	return rhs < lhs;
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
	return !(lhs < rhs);
}

}

#endif
