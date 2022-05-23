/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:08:57 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 05:52:36 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

# include "algorithm.hpp"

namespace	ft
{

template <	typename T,
			typename Allocator >
class	vector;

}

# include "vector_iterator.hpp"

namespace	ft
{

template <	typename T,
			typename Allocator = std::allocator<T> >
class	vector
{
public:
	/* ---------------------------------------- */
	/*               Member Types               */
	/* ---------------------------------------- */

	typedef T									value_type;
	typedef Allocator							allocator_type;
	typedef std::size_t							size_type;
	typedef std::ptrdiff_t						difference_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;

	typedef vector_iterator<vector, false>		iterator;
	typedef vector_iterator<vector, true>		const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	/* ---------------------------------------- */
	/*             Member Functions             */
	/* ---------------------------------------- */

	/* constructor */

	vector() : _alloc(Allocator()), _size(0), _capacity(0) { _data = _alloc.allocate(_capacity); };

	explicit vector(const Allocator& alloc) : _alloc(alloc), _size(0), _capacity(0) { _data = _alloc.allocate(_capacity); };
	explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		: _alloc(alloc), _capacity(count)
	{
		_data = _alloc.allocate(_capacity);
		for (_size = 0; _size < count; _size++)
			_alloc.construct(_data + _size, value);
	}

	template <	typename InputIt >
	vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(),
			typename ft::enable_if<!is_integral<InputIt>::value>::type = 0)
		: _alloc(alloc), _size(0)
	{
		for (InputIt itr = first; itr != last; itr++)
			_size++;
		_capacity = _size;
		_data = _alloc.allocate(_capacity);
		for (size_type i = 0; first != last; first++, i++)
			_alloc.construct(_data + i, *first);
	}

	vector(const vector& other) : _alloc(other._alloc), _capacity(other._capacity)
	{
		_data = _alloc.allocate(_capacity);
		for (_size = 0; _size < other._size; _size++)
			_alloc.construct(_data + _size, other[_size]);
	}

	/* destructor */
	~vector()
	{
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_alloc.deallocate(_data, _capacity);
	}

	/* operator= */
	vector&	operator=(const vector& other)
	{
		vector	other_copy = other;

		swap(other_copy);
		return (*this);
	}

	/* assign */
	void	assign(size_type count, const T& value)
	{
		erase(begin(), end());
		insert(begin(), count, value);
	}

	template <	typename InputIt >
	void	assign(InputIt first, InputIt last,
			typename ft::enable_if<!is_integral<InputIt>::value>::type = 0)
	{
		erase(begin(), end());
		insert(begin(), first, last);
	}

	/* get_allocator */
	allocator_type	get_allocator() const { return _alloc; }

	/* ---------------------------------------- */
	/*              Element Access              */
	/* ---------------------------------------- */

	/* at */
	reference		at(size_type pos)
	{
		if (pos >= _size)
		{
			throw (std::out_of_range("vector"));
		}
		return (_data[pos]);
	}

	const_reference	at(size_type pos) const
	{
		if (pos >= _size)
		{
			throw (std::out_of_range("vector"));
		}
		return (_data[pos]);
	}

	/* oprator[] */
	reference		operator[](size_type pos)		{ return _data[pos]; }
	const_reference	operator[](size_type pos) const	{ return _data[pos]; }

	/* front */
	reference		front()			{ return _data[0]; }
	const_reference	front() const	{ return _data[0]; }

	/* back */
	reference		back()			{ return _data[_size - 1]; }
	const_reference	back() const	{ return _data[_size - 1]; }

	/* ---------------------------------------- */
	/*                Iterators                 */
	/* ---------------------------------------- */

	/* begin */
	iterator		begin()			{ return iterator(_data); }
	const_iterator	begin() const	{ return const_iterator(_data); }

	/* end */
	iterator		end()			{ return iterator(_data + _size); }
	const_iterator	end() const		{ return const_iterator(_data + _size); }

	/* rbegin */
	reverse_iterator		rbegin()		{ return reverse_iterator(iterator(_data + _size - 1)); }
	const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(const_iterator(_data + _size - 1)); }

	/* rend */
	reverse_iterator		rend()			{ return reverse_iterator(iterator(_data - 1)); }
	const_reverse_iterator	rend() const	{ return const_reverse_iterator(const_iterator(_data - 1)); }

	/* ---------------------------------------- */
	/*                 Capacity                 */
	/* ---------------------------------------- */

	/* empty */
	bool		empty() const		{ return (_size == 0); }

	/* size */
	size_type	size() const		{ return (_size); }

	/* max_size */
	size_type	max_size() const	{ return (_alloc.max_size()); }

	/* reverse */
	void		reserve(size_type new_cap)
	{
		if (new_cap <= _capacity)
			return ;
		if (new_cap > max_size())
		{
			throw (std::length_error("vector"));
		}
		_resize_capacity(new_cap);
	}

	/* capacity */
	size_type	capacity() const	{ return (_capacity); }

	/* ---------------------------------------- */
	/*                Modifiers                 */
	/* ---------------------------------------- */

	/* clear */
	void	clear()
	{
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_alloc.deallocate(_data, _capacity);
		_size = 0;
		_capacity = 0;
		_data = _alloc.allocate(_capacity);
	}

	/* insert */
	iterator	insert(iterator pos, const T& value)
	{
		difference_type	pos_index = pos - begin();

		insert(pos, 1, value);
		return iterator(_data + pos_index);
	}

	void		insert(iterator pos, size_type count, const T& value)
	{
		//     pos            end
		//      │              │
		//     (c)(c)(c)(c)(c)(d)(d)(d)(d)
		// to
		//     pos
		//      │
		//     (d)(d)(d)(c)(c)(c)(c)(c)(d)
		//               │              │
		//           pos + count       end
		// to
		//     pos
		//      │
		//     (i)(i)(i)(c)(c)(c)(c)(c)(d)
		//               │              │
		//           pos + count       end

		difference_type	pos_index = pos - begin();

		if (_size + count > _capacity)
		{
			size_type	new_cap = (_capacity == 0 ? 32 : _capacity * 2);

			while (_size + count > new_cap)
				new_cap *= 2;
			_resize_capacity(new_cap);
			pos = begin() + pos_index;
		}
		_move_datas(pos, end() - pos, count);
		for (size_type i = 0; i < count; i++)
			_alloc.construct(_data + pos_index + i, value);
		_size += count;
	}

	template <	typename InputIt >
	void		insert(iterator pos, InputIt first, InputIt last,
					typename ft::enable_if<!is_integral<InputIt>::value>::type = 0)
	{
		difference_type	pos_index	= pos - begin();
		size_type		count		= 0;

		for (InputIt itr = first; itr != last; itr++)
			count++;
		if (_size + count > _capacity)
		{
			size_type	new_cap = (_capacity == 0 ? 32 : _capacity * 2);

			while (_size + count > new_cap)
				new_cap *= 2;
			_resize_capacity(new_cap);
			pos = begin() + pos_index;
		}
		_move_datas(pos, end() - pos, count);
		for (size_type i = 0; i < count; i++)
			_alloc.construct(_data + pos_index + i, *first++);
		_size += count;
	}

	/* erase */
	iterator	erase(iterator pos)
	{
		return erase(pos, pos + 1);
	}

	iterator	erase(iterator first, iterator last)
	{
		//    first     last           end
		//      │        │              │
		//     (c)(c)(c)(1)(2)(3)(4)(5)(d)
		// to
		//    first     last           end
		//      │        │              │
		//     (d)(d)(d)(1)(2)(3)(4)(5)(d)
		// to
		//     (1)(2)(3)(4)(5)(d)(d)(d)(d)
		//      │
		//    first

		if (first == last)
			return first;

		for (iterator itr = first; itr != last; itr++)
			_alloc.destroy(&(*itr));
		_move_datas(last, end() - last, -(last - first));
		_size -= last - first;
		return (first);
	}

	/* push_back */
	void		push_back(const T& value)
	{
		insert(end(), value);
	}

	/* pop_back */
	void		pop_back()
	{
		erase(end() - 1);
	}

	/* resize */
	void		resize(size_type count, T value = T())
	{
		if (count < _size)
			erase(begin() + count, end());
		else if (count > _size)
			insert(end(), count - _size, value);
	}

	/* swap */
	void		swap(vector& other)
	{
		ft::swap(_alloc, other._alloc);
		ft::swap(_data, other._data);
		ft::swap(_size, other._size);
		ft::swap(_capacity, other._capacity);
	}

	/* ---------------------------------------- */
	/*           Non-member Functions           */
	/* ---------------------------------------- */

	/* operatpr== */
	friend	bool	operator==(const vector& lhs, const vector& rhs)
	{
		if (lhs._size != rhs._size)
			return false;

		const_iterator	lhs_itr;
		const_iterator	rhs_itr;

		for (lhs_itr = lhs.begin(), rhs_itr = rhs.begin(); lhs_itr != lhs.end(); lhs_itr++, rhs_itr++)
		{
			if (*lhs_itr != *rhs_itr)
				return false;
		}
		return true;
	}

	/* operatpr!= */
	friend	bool	operator!=(const vector& lhs, const vector& rhs)
	{
		return !(lhs == rhs);
	}

	/* operatpr< */
	friend	bool	operator<(const vector& lhs, const vector& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	/* operatpr<= */
	friend	bool	operator<=(const vector& lhs, const vector& rhs)
	{
		return !(rhs < lhs);
	}

	/* operatpr> */
	friend	bool	operator>(const vector& lhs, const vector& rhs)
	{
		return rhs < lhs;
	}

	/* operatpr>= */
	friend	bool	operator>=(const vector& lhs, const vector& rhs)
	{
		return !(lhs < rhs);
	}

private:
	void	_resize_capacity(size_type new_cap)
	{
		pointer	new_data = _alloc.allocate(new_cap);

		for (size_type i = 0; i < _size && i < new_cap; i++)
			_alloc.construct(new_data + i, _data[i]);
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_data + i);
		_alloc.deallocate(_data, _capacity);
		_data = new_data;
		_capacity = new_cap;
	}

	void	_move_datas(iterator pos, size_type size, difference_type length)
	{
		if (size == 0 || length == 0)
			return ;

		ptrdiff_t	pos_index = pos - begin();

		// length < 0:
		//              pos         pos + size
		//               │              │
		//     (d)(d)(d)(1)(2)(3)(4)(5)(d)
		// to
		//     (1)(2)(3)(4)(5)(d)(d)(d)(d)
		//      │
		// pos + length
		if (length < 0)
		{
			for (size_type i = 0; i < size; i++)
			{
				_alloc.construct(_data + pos_index + length + i, _data[pos_index + i]);
				_alloc.destroy(_data + pos_index + i);
			}
		}

		// length > 0:
		//     pos    pos + size - 1
		//      │           │
		//     (5)(4)(3)(2)(1)(d)(d)(d)(d)
		// to
		//     (d)(d)(d)(5)(4)(3)(2)(1)(d)
		//                           │
		//                pos + size - 1 + length
		else if (length > 0)
		{
			for (size_type i = 0; i < size; i++)
			{
				_alloc.construct(_data + pos_index + size - 1 + length - i, _data[pos_index + size - 1 - i]);
				_alloc.destroy(_data + pos_index + size - 1 - i);
			}
		}
	}

	allocator_type	_alloc;
	pointer			_data;
	size_type		_size;
	size_type		_capacity;
};

// template <	typename Allocator >
// class	vector<bool, Allocator>
// {
// public:
// 	typedef bool			value_type;
// 	typedef Allocator		allocator_type;
// 	typedef std::size_t		size_type;
// 	typedef std::ptrdiff_t	difference_type;
// 	typedef bool			const_reference;

// 	typedef vector_iterator<vector, false>		iterator;
// 	typedef vector_iterator<vector, true>		const_iterator;
// 	typedef ft::reverse_iterator<iterator>			reverse_iterator;
// 	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

// 	typedef iterator		pointer;
// 	typedef const_iterator	const_pointer;

// 	class	reference
// 	{
// 	public:
// 		reference(typename allocator_type::pointer data, size_type idx) : _data(data), _idx(idx) {}
// 		reference(const reference& other) : _data(other._data), _idx(other._idx) {}
// 		~reference() {};

// 		operator	bool() const
// 		{
// 			return ((_data[_idx / _alloc_bitsize] >> (_idx % _alloc_bitsize)) & 1U);
// 		}

// 		reference&	operator=(bool other)
// 		{
// 			_data[_idx / _alloc_bitsize] =
// 					(_data[_idx / _alloc_bitsize] & ~(1UL << (_idx % _alloc_bitsize))) | (other << (_idx % _alloc_bitsize));
// 			return (*this);
// 		}
// 		reference&	operator=(const reference& other)
// 		{
// 			return (reference::operator=(static_cast<bool>(other)));
// 		}

// 		void		flip()
// 		{
// 			_data[_idx / _alloc_bitsize] ^= (1UL << (_idx % _alloc_bitsize));
// 		}
// 	private:
// 		typedef typename Allocator::pointer	base_pointer;

// 		reference();

// 		base_pointer	_data;
// 		size_type		_idx;

// 	};

// 	/* constructor */
// 	vector() : _alloc(Allocator()), _size(0), _capacity(0) { _data = _alloc.allocate(_capacity / _alloc_bitsize); }

// 	explicit vector(const Allocator& alloc) : _alloc(alloc), _size(0), _capacity(0) { _data = _alloc.allocate(_capacity / _alloc_bitsize); }
// 	explicit vector(size_type count, const bool& value = bool(), const Allocator& alloc = Allocator())
// 		: _alloc(alloc), _size(count), _capacity((count + _alloc_bitsize - 1) / _alloc_bitsize * _alloc_bitsize)
// 	{
// 		_data = _alloc.allocate(_capacity / _alloc_bitsize);
// 		for (size_type itr = 0; itr < _capacity / _alloc_bitsize; itr++)
// 		{
// 			if (value)
// 				_data[itr] = ~(0UL);
// 			else
// 				_data[itr] = 0UL;
// 		}
// 	}

// 	template <	typename InputIt >
// 	vector(InputIt first, InputIt last, const Allocator& alloc = Allocator().
// 			ft::enable_if<!is_integral<InputIt>::value>::type = 0)
// 		: _alloc(alloc), _size(0)
// 	{
// 		for (InputIt itr = first; itr != last; itr++)
// 			_size++;
// 		_capacity = (_size + _alloc_bitsize - 1) / _alloc_bitsize * _alloc_bitsize;
// 		_data = _alloc.allocate(_capacity / _alloc_bitsize);
// 		for (iterator itr = begin(); first != last; first++, itr++)
// 			*itr = *first;
// 	}

// 	vector(const vector& other) : _alloc(other._alloc), _capacity(other._capacity)
// 	{
// 		_data = _alloc.allocate(_capacity / _alloc_bitsize);
// 		for (iterator litr = begin(), ritr = other.begin(); ritr != other.end(); litr++, ritr++)
// 			*litr = *ritr;
// 	}

// 	/* destructor */
// 	~vector()
// 	{
// 		_alloc.deallocate(_data, _capacity);
// 	}

// 	/* operator= */
// 	vector&	operator=(const vector& other)
// 	{
// 		vector	other_copy = other;

// 		swap(other_copy);
// 		return (*this);
// 	}

// 	/* assign */
// 	void	assign(size_type count, const bool& value)
// 	{
// 		erase(begin(), end());
// 		insert(begin(), count, value);
// 	}

// 	template <	typename InputIt >
// 	void	assign(InputIt first, InputIt last,
// 			typename ft::enable_if<!is_integral<InputIt>::value>::type = 0)
// 	{
// 		erase(begin(), end());
// 		insert(begin(), first, last);
// 	}

// 	/* get_allocator */
// 	allocator_type	get_allocator() const { return _alloc; }

// 	/* ---------------------------------------- */
// 	/*              Element Access              */
// 	/* ---------------------------------------- */

// 	/* at */
// 	reference		at(size_type pos)
// 	{
// 		return (reference(_data, pos));
// 	}

// 	const_reference	at(size_type pos) const
// 	{
// 		return (reference(_data, pos));
// 	}

// 	/* operator[] */
// 	reference		operator[](size_type pos)
// 	{
// 		return (reference(_data, pos));
// 	}

// 	const_reference	operator[](size_type pos) const
// 	{
// 		return (reference(_data, pos));
// 	}

// 	/* front */
// 	reference		front()
// 	{
// 		return (at(0));
// 	}

// 	const_reference	front() const
// 	{
// 		return (at(0));
// 	}

// 	/* back */
// 	reference		back()
// 	{
// 		return (at(_size - 1));
// 	}

// 	const_reference	back() const
// 	{
// 		return (at(_size - 1));
// 	}

// 	/* ---------------------------------------- */
// 	/*                Iterators                 */
// 	/* ---------------------------------------- */

// 	/* begin */
// 	iterator		begin()			{ return iterator(_data, 0); }
// 	const_iterator	begin() const	{ return const_iterator(_data, 0); }

// 	/* end */
// 	iterator		end()			{ return iterator(_data, _size); }
// 	const_iterator	end() const		{ return const_iterator(_data, _size); }

// 	/* rbegin */
// 	reverse_iterator		rbegin()		{ return reverse_iterator(iterator(_data, _size - 1)); }
// 	const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(iterator(_data, _size - 1)); }

// 	/* rend */
// 	reverse_iterator		rend()			{ return reverse_iterator(iterator(_data, -1)); }
// 	const_reverse_iterator	rend() const	{ return const_reverse_iterator(iterator(_data, -1)); }

// 	/* ---------------------------------------- */
// 	/*                 Capacity                 */
// 	/* ---------------------------------------- */

// 	/* empty */
// 	bool		empty() const		{ return (_size == 0); }

// 	/* size */
// 	size_type	size() const		{ return (_size); }

// 	/* max_size */
// 	size_type	max_size() const	{ return (_alloc.max_size()); }

// 	/* reserve */
// 	void		reserve(size_type new_cap)
// 	{
// 		if (new_cap <= _capacity)
// 			return ;
// 		if (new_cap > max_size())
// 		{
// 			std::stringstream	ss;

// 			ss << "new_cap: " << new_cap << ", max_size(): " << max_size();
// 			throw (std::length_error(ss.str()));
// 		}
// 		_resize_capacity(new_cap);
// 	}

// 	/* capacity */
// 	size_type	capacity() const	{ return (_capacity); }

// 	/* ---------------------------------------- */
// 	/*                Modifiers                 */
// 	/* ---------------------------------------- */

// 	/* clear */
// 	void		clear()
// 	{
// 		_alloc.deallocate(_data, _capacity);
// 		_size = 0;
// 		_capacity = 0;
// 		_data = _alloc.allocate(_capacity);
// 	}

// 	/* insert */
// 	iterator	insert(iterator pos, const bool& value)
// 	{
// 		difference_type	pos_index = pos - begin();

// 		insert(pos, 1, value);
// 		return iterator(_data, pos_index);
// 	}

// 	void		insert(iterator pos, size_type count, const bool& value)
// 	{
// 		difference_type	pos_index = pos - begin();

// 		if (_size + count > _capacity)
// 		{
// 			size_type	new_cap = (_capacity == 0 ? 32 : _capacity * 2);

// 			while (_size + count > new_cap)
// 				new_cap *= 2;
// 			_resize_capacity(new_cap);
// 			pos = begin() + pos_index;
// 		}
// 		_move_datas(pos, end() - pos, count);
// 		for (size_type i = 0; i < count; i++)
// 		{
// 			reference	ref(_data, pos_index + i);

// 			ref = value;
// 		}
// 		_size += count;
// 	}

// 	template <	typename InputIt >
// 	void		insert(iterator pos, InputIt first, InputIt last,
// 					typename ft::enable_if<!is_integral<InputIt>::value>::type = 0)
// 	{
// 		difference_type	pos_index	= pos - begin();
// 		size_type		count		= 0;

// 		for (InputIt itr = first; itr != last; itr++)
// 			count++;
// 		if (_size + count > _capacity)
// 		{
// 			size_type	new_cap = (_capacity == 0 ? 32 : _capacity * 2);

// 			while (_size + count > new_cap)
// 				new_cap *= 2;
// 			_resize_capacity(new_cap);
// 			pos = begin() + pos_index;
// 		}
// 		_move_datas(pos, end() - pos, count);
// 		for (size_type i = 0; i < count; i++)
// 		{
// 			reference	ref(_data, pos_index + i);

// 			ref = *first++;
// 		}
// 		_size += count;
// 	}

// 	/* erase */
// 	iterator	erase(iterator pos)
// 	{
// 		return erase(pos, pos + 1);
// 	}

// 	iterator	erase(iterator first, iterator last)
// 	{
// 		if (first == last)
// 			return first;

// 		_move_datas(last, end() - last, -(last - first));
// 		_size -= last - first;
// 		return (first);
// 	}

// 	/* push_back */
// 	void		push_back(const bool& value)
// 	{
// 		insert(end(), value);
// 	}

// 	/* pop_back */
// 	void		pop_back()
// 	{
// 		erase(end() - 1);
// 	}

// 	/* resize */
// 	void		resize(size_type count, bool value = bool())
// 	{
// 		if (count < _size)
// 			erase(begin() + count, end());
// 		else if (count > _size)
// 			insert(end(), count - _size, value);
// 	}

// 	/* swap */
// 	void		swap(vector& other)
// 	{
// 		ft::swap(_alloc, other._alloc);
// 		ft::swap(_data, other._data);
// 		ft::swap(_size, other._size);
// 		ft::swap(_capacity, other._capacity);
// 	}

// 	/* ---------------------------------------- */
// 	/*     vector<bool> specific modifiers      */
// 	/* ---------------------------------------- */

// 	/* flip */
// 	void		flip()
// 	{
// 		for (size_type i = 0; i < _capacity / _alloc_bitsize; i++)
// 			_data[i] = ~(_data[i]);
// 	}

// 	/* swap */
// 	static void	swap(reference x, reference y)
// 	{
// 		reference	temp;

// 		temp = x;
// 		x = y;
// 		y = temp;
// 	}

// 	/* ---------------------------------------- */
// 	/*           Non-member Functions           */
// 	/* ---------------------------------------- */

// 	/* operator== */
// 	friend bool	operator==(const vector& lhs, const vector& rhs)
// 	{
// 		if (lhs._size != rhs._size)
// 			return false;

// 		const_iterator	lhs_itr;
// 		const_iterator	rhs_itr;

// 		for (lhs_itr = lhs.begin(), rhs_itr = rhs.begin(); lhs_itr != lhs.end(); lhs_itr++, rhs_itr++)
// 		{
// 			if (*lhs_itr != *rhs_itr)
// 				return false;
// 		}
// 		return true;
// 	}

// 	/* operator!= */
// 	friend bool	operator!=(const vector& lhs, const vector& rhs)
// 	{
// 		return !(lhs == rhs);
// 	}

// 	/* operator< */
// 	friend bool	operator<(const vector& lhs, const vector& rhs)
// 	{
// 		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
// 	}

// 	/* operator<= */
// 	friend bool	operator<=(const vector& lhs, const vector& rhs)
// 	{
// 		return !(rhs < lhs);
// 	}

// 	/* operator> */
// 	friend bool	operator>(const vector& lhs, const vector& rhs)
// 	{
// 		return rhs < lhs;
// 	}

// 	/* operator>= */
// 	friend bool	operator>=(const vector& lhs, const vector& rhs)
// 	{
// 		return !(lhs < rhs);
// 	}

// private:
// 	typedef typename allocator_type::pointer	base_pointer;

// 	void	_resize_capacity(size_type new_cap)
// 	{
// 		base_pointer	new_data = _alloc.allocate(new_cap / _alloc_bitsize);

// 		for (size_type i = 0; i < _capacity / _alloc_bitsize && i < new_cap / _alloc_bitsize; i++)
// 			_alloc.construct(new_data + i, _data[i]);
// 		for (size_type i = 0; i < _capacity / _alloc_bitsize; i++)
// 			_alloc.destroy(_data + i);
// 		_alloc.deallocate(_data, _capacity / _alloc_bitsize);
// 		_data = new_data;
// 		_capacity = new_cap;
// 	}

// 	void	_move_datas(iterator pos, size_type size, difference_type length)
// 	{
// 		if (size == 0 || length == 0)
// 			return ;

// 		// length < 0:
// 		//              pos         pos + size
// 		//               │              │
// 		//     (d)(d)(d)(1)(2)(3)(4)(5)(d)
// 		// to
// 		//     (1)(2)(3)(4)(5)(d)(d)(d)(d)
// 		//      │
// 		// pos + length
// 		if (length < 0)
// 		{
// 			iterator	target = pos + length;

// 			for (size_type i = 0; i < size; i++)
// 				*target++ = *pos++;
// 		}

// 		// length > 0:
// 		//     pos    pos + size - 1
// 		//      │           │
// 		//     (5)(4)(3)(2)(1)(d)(d)(d)(d)
// 		// to
// 		//     (d)(d)(d)(5)(4)(3)(2)(1)(d)
// 		//                           │
// 		//                pos + size - 1 + length
// 		else if (length > 0)
// 		{
// 			iterator	target;

// 			pos = pos + size - 1;
// 			target = pos + length;
// 			for (size_type i = 0; i < size; i++)
// 				*target-- = *pos--;
// 		}
// 	}

// 	static const size_type	_alloc_bitsize;

// 	base_pointer			_data;

// 	allocator_type			_alloc;
// 	size_type				_size;
// 	size_type				_capacity;
// };

template <	typename T, typename Alloc >
void	swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)	{ lhs.swap(rhs); }

// template <	typename Allocator >
// const typename vector<bool, Allocator>::size_type
// 	vector<bool, Allocator>::_alloc_bitsize = sizeof(typename Allocator::value_type) * 8;

}

#endif
