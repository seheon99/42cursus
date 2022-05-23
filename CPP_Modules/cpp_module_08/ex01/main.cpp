/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:30:13 by seyu              #+#    #+#             */
/*   Updated: 2021/04/15 04:38:55 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <sys/time.h>

#include <vector>

#include "Span.hpp"

#define NUM_OF_ARRAY(A) (sizeof(A) / sizeof(A[0]))

template<typename T>
void
	setRandomValues(T begin, T end, int min, int max)
{
	for (T itr = begin; itr != end; itr++)
		*itr = std::rand() % (max - min + 1) + min;
}

template<typename T>
void
	addNumber(Span& target, T begin, T end)
{
	for (T itr = begin; itr != end; itr++)
		target.addNumber(*itr);
}

static void
	showSpan(std::string name, Span target)
{
	std::cout << name << " has the values: " << target << std::endl;
	std::cout << "The shortest span is ";
	try
	{
		std::cout << target.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl;
		std::cout << "Exception occured: " << e.what() << std::endl;
	}
	std::cout << "The longest span is ";
	try
	{
		std::cout << target.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl;
		std::cout << "Exception occured: " << e.what() << std::endl;
	}
}

static void
	testSpan(int n)
{
	Span				mySpan(n);
	std::vector<int>	vector(n);

	setRandomValues(vector.begin(), vector.end(), 1, n * 10);
	addNumber(mySpan, vector.begin(), vector.end());
	std::cout << std::endl;
	std::cout << n;
	showSpan(" elements", mySpan);
}

int main(void)
{
	try
	{
		std::cout << "==Subject's main==" << std::endl;
		{
			Span	sp = Span(5);

			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "==My main==" << std::endl;
		{
			std::srand(time(NULL));

			testSpan(1);
			testSpan(2);
			testSpan(3);
			testSpan(5);
			testSpan(10);
			testSpan(100);
			testSpan(10000);

			Span				mySpan(10);
			std::vector<int>	vec(10);

			std::cout << std::endl;
			setRandomValues(vec.begin(), vec.end(), 1, 10);
			addNumber(mySpan, vec.begin(), vec.end());
			try
			{
				std::cout << "Add a number to the full Span" << std::endl;
				mySpan.addNumber(100);
			}
			catch (const std::exception& e)
			{
				std::cout << "Exception occured: " << e.what() << std::endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << " (                                                                           ____" << std::endl;
		std::cout << " )\\ )                    )   )                 (  (                         |   /" << std::endl;
		std::cout << "(()/(        )     (  ( /(( /((        (  (    )\\))(   '(             (  (  |  / " << std::endl;
		std::cout << " /(_)) (    (     ))\\ )\\())\\())\\  (    )\\))(  ((_)()\\ ) )(   (   (    )\\))( | /  " << std::endl;
		std::cout << "(_))   )\\   )\\  '/((_|_))((_)((_) )\\ )((_))\\  _(())\\_)(|()\\  )\\  )\\ )((_))\\ |/   " << std::endl;
		std::cout << "/ __| ((_)_((_))(_)) | |_| |(_|_)_(_/( (()(_) \\ \\((_)/ /((_)((_)_(_/( (()(_|     " << std::endl;
		std::cout << "\\__ \\/ _ \\ '  \\() -_)|  _| ' \\| | ' \\)) _` |   \\ \\/\\/ /| '_/ _ \\ ' \\)) _` |)\\    " << std::endl;
		std::cout << "|___/\\___/_|_|_|\\___| \\__|_||_|_|_||_|\\__, |    \\_/\\_/ |_| \\___/_||_|\\__, ((_)   " << std::endl;
		std::cout << "                                      |___/                          |___/       " << std::endl;

		std::cout << ":( Something wrong with your main code" << std::endl;
		std::cout << "Please catch all exception you intended (exception message: " << e.what() << ")" << std::endl;
	}
}
