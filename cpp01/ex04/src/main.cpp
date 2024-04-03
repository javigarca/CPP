/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:46:29 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 17:46:31 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceline(std::string& line, const std::string& tofind, const std::string& toreplace)
{
    size_t pos = 0;
    size_t prev = 0;
    std::string replaced;

    while ((pos = line.find(tofind, pos)) != std::string::npos)
    {
        replaced += line.substr(prev, pos - prev) + toreplace;
        pos += tofind.length();
        prev = pos;      
    }
    if (prev != 0)
    {
        if (prev != line.length())
            replaced += line.substr(prev, line.length() - prev);
        line = replaced;
    }
}

int main(int argc, char* argv[])
{
     
    if (argc != 4)
    {
        std::cout << "Incorrect number of parameters." << std::endl;
        std::cout << "Usage: " << argv[0] << " <filename> <string_to_replace> <replace_string>." << std::endl;
    }
    else
    {
        
        std::string tofind = argv[2];
        if (tofind.empty())
        {
            std::cout << "Nothing to search for, nothing to replace then." << std::endl;
            return 0;
        }
        std::string toreplace = argv[3];
        std::string filename = argv[1];
        std::ifstream ifs(filename);

        if (!ifs.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return 1;
        }
        filename += ".replace";
        std::ofstream ofs(filename);
        if (!ofs.is_open())
        {
            std::cerr << "Error creating replace file: " << filename << std::endl;
            ifs.close();
            return 1;
        }
        std::string line;
        while (std::getline(ifs, line))
        {
            replaceline(line, tofind, toreplace);
            ofs << line << std::endl;
        }

        ifs.close();
        ofs.close();
    }
    return 0;
}
