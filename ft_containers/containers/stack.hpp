/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 03:54:04 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 06:26:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <cassert>

# include "vector.hpp"
# include "type_traits.hpp"

namespace	ft
{

template <	typename T, typename Container = ft::vector<T> >
class	stack
{
public:
	typedef Container							container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;

	explicit stack(const container_type& container = container_type()) : c(container) {}
	stack(const stack& other) : c(other.c) {}
	~stack() {}

	stack&	operator=(const stack& other)
	{
		stack	other_copy = stack(other);

		c.swap(other_copy.c);
		return (*this);
	}

	/* ---------------------------------------- */
	/*              Element Access              */
	/* ---------------------------------------- */

	reference		top()		{ return (c.back()); }
	const_reference	top() const	{ return (c.back()); }

	/* ---------------------------------------- */
	/*                 Capacity                 */
	/* ---------------------------------------- */

	bool			empty() const	{ return (c.empty()); }
	size_type		size() const	{ return (c.size()); }

	/* ---------------------------------------- */
	/*                Modifiers                 */
	/* ---------------------------------------- */

	void			push(const value_type& value)	{ c.push_back(value); }
	void			pop()							{ c.pop_back(); }

	/* ---------------------------------------- */
	/*           Non-member Functions           */
	/* ---------------------------------------- */

	friend bool	operator==(const stack& lhs, const stack& rhs)	{ return (lhs.c == rhs.c); }
	friend bool	operator!=(const stack& lhs, const stack& rhs)	{ return (lhs.c != rhs.c); }
	friend bool	operator< (const stack& lhs, const stack& rhs)	{ return (lhs.c <  rhs.c); }
	friend bool	operator<=(const stack& lhs, const stack& rhs)	{ return (lhs.c <= rhs.c); }
	friend bool	operator> (const stack& lhs, const stack& rhs)	{ return (lhs.c >  rhs.c); }
	friend bool	operator>=(const stack& lhs, const stack& rhs)	{ return (lhs.c >= rhs.c); }

protected:
	container_type	c;
private:
	typedef typename enable_if<is_same<T, value_type>::value >::type	_check_valid;
};

}

#endif
