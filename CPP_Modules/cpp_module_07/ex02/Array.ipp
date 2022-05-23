/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 06:24:28 by seyu              #+#    #+#             */
/*   Updated: 2021/04/13 23:45:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <stdexcept>

template<class T>
class	Array
{
public:
	Array() : _size(0), _array(NULL) {}
	Array(unsigned int n) : _size(n), _array(NULL)
	{
		if (_size > 0)
			_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = T();
	}
	Array(const Array& other) : _size(other._size), _array(NULL)
	{
		if (_size > 0)
			_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = T(other._array[i]);
	}
	~Array()
	{
		if (_array)
			delete[] _array;
	}

	Array& operator=(const Array& other)
	{
		if (_array)
			delete[] _array;
		_size = other._size;
		if (_size > 0)
			_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
		return (*this);
	}

	T& operator[](unsigned int idx)
	{
		if (idx >= _size)
			throw std::out_of_range("Out of range.");
		return (_array[idx]);
	}

	unsigned int size(void) const { return (_size); };
private:
	unsigned int	_size;
	T*				_array;
};

#endif
