/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 04:40:22 by seyu              #+#    #+#             */
/*   Updated: 2021/04/15 05:54:44 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<
	typename T,
	class Container = std::deque<T>
>
class	MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other) {}
	~MutantStack() {}

	MutantStack&
		operator=(const MutantStack& other)
	{
		if (this == &other)
			return (*this);
		std::stack<T, Container>::operator=(other);
		return (*this);
	};

	MutantStack&
		operator=(const std::stack<T, Container>& other)
	{
		if (this == &other)
			return (*this);
		std::stack<T, Container>::operator=(other);
		return (*this);
	}

	typedef	typename std::stack<T, Container>::container_type::iterator					iterator;
	typedef	typename std::stack<T, Container>::container_type::const_iterator			const_iterator;
	typedef	typename std::stack<T, Container>::container_type::reverse_iterator			reverse_iterator;
	typedef	typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator
		begin(void)
	{
		return (std::stack<T, Container>::c.begin());
	}
	iterator
		end(void)
	{
		return (std::stack<T, Container>::c.end());
	}

	const_iterator
		begin(void) const
	{
		return (std::stack<T, Container>::c.begin());
	}
	const_iterator
		end(void) const
	{
		return (std::stack<T, Container>::c.end());
	}

	reverse_iterator
		rbegin(void)
	{
		return (std::stack<T, Container>::c.rbegin());
	}
	reverse_iterator
		rend(void)
	{
		return (std::stack<T, Container>::c.rend());
	}

	const_reverse_iterator
		rbegin(void) const
	{
		return (std::stack<T, Container>::c.rbegin());
	}
	const_reverse_iterator
		rend(void) const
	{
		return (std::stack<T, Container>::c.rend());
	}
private:
};

#endif
