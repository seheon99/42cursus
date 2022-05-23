/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:14:52 by seyu              #+#    #+#             */
/*   Updated: 2021/04/13 23:36:14 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.ipp"

template<class T>
static void
	checkArray(std::string name, Array<T>& arr)
{
	unsigned int	size;

	size = arr.size();
	std::cout << name << ": ";
	for (unsigned int i = 0; i < size; i++)
		std::cout << "[" << arr[i] << "] ";
	std::cout << "(" << size << ")" << std::endl;
}

template<class T>
static void
	initArray(Array<T>& arr, T* data, unsigned int dataSize)
{
	arr = Array<T>(dataSize);
	try
	{
		for (unsigned int i = 0; i < dataSize; i++)
			arr[i] = data[i];
	}
	catch (const std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
}

template<class T>
static void
	catchException(Array<T>& arr)
{
	try
	{
		std::cout << arr[-1];
	}
	catch (const std::exception& e)
	{
		std::cout << "Throw an exception when the iterator is -1: " << e.what() << std::endl;
	}

	try
	{
		std::cout << arr[arr.size()];
	}
	catch (const std::exception& e)
	{
		std::cout << "Throw an exception when the iterator is it's size: " << e.what() << std::endl;
	}
}

int	main(void)
{
	Array<int>		emptyArray;
	checkArray("empty array", emptyArray);
	std::cout << std::endl;

	Array<int>		defaultArray(10);
	checkArray("default int array", defaultArray);
	std::cout << std::endl;

	Array<float>	floatArray;
	float			floatData[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f};
	initArray(floatArray, floatData, 10);
	checkArray("float array", floatArray);
	std::cout << std::endl;

	Array<float>	copiedFloatArray;
	float			anotherFloatData[] = {4.1f, 4.2f, 4.3f, 4.4f, 4.5f, 4.6f, 4.7f, 4.8f, 4.9f, 5.0f};
	copiedFloatArray = Array<float>(floatArray);
	checkArray("copied float array", copiedFloatArray);
	initArray(copiedFloatArray, anotherFloatData, 10);
	checkArray("changed float array", copiedFloatArray);
	checkArray("origin float array", floatArray);
	std::cout << std::endl;

	Array<std::string>	strArray;
	std::string			strData[] = {"Lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit.", "Nunc", "bibendum."};
	initArray(strArray, strData, 10);
	checkArray("string array", strArray);
	std::cout << std::endl;
	catchException(strArray);
	return (0);
}
