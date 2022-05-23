/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 05:37:20 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 15:50:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	std::string		filename, s1, s2;
	if (argc != 4 || (filename = argv[1]).empty() || (s1 = argv[2]).empty()|| (s2 = argv[3]).empty())
	{
		std::cout << "Invalid Usage" << std::endl;
		std::cout << "$ " << argv[0] << " <File Name> <Source String> <Destination String>" << std::endl;
		return (1);
	}

	std::ifstream	fin(filename);
	std::ofstream	fout(filename + ".replace");
	if (!fin.is_open() || !fout.is_open())
	{
		if (!fin.is_open())
			std::cout << "Unable to open file to read: " << filename << std::endl;
		else if (!fout.is_open())
			std::cout << "Unable to open file to write: " << filename + ".replace" << std::endl;
		fin.close();
		fout.close();
		return (1);
	}

	std::string	input_line;
	std::string	output_file;
	size_t		src_idx;
	while (std::getline(fin, input_line))
	{
		output_file += input_line;
		if (fin.eof() == false)
			output_file += "\n";
	}
	while ((src_idx = output_file.find(s1)) != std::string::npos)
		output_file.replace(src_idx, s1.size(), s2);
	fout << output_file;
	return (0);
}
