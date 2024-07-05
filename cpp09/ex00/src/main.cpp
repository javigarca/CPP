#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date)
{
    std::istringstream ss(date);
    int year, month, day;
    char delim1, delim2;
    
    if (ss >> year >> delim1 >> month >> delim2 >> day) 
    {
        if (delim1 == '-' && delim2 == '-' && year > 2000 && month > 0 && month <= 12)
        {
            if (day > 0) 
            {
                switch (month) 
                {
                    case 2: // February
                        if (isLeapYear(year)) 
                            return day <= 29;
                        else 
                            return day <= 28;
                    case 4: case 6: case 9: case 11: // April, June, September, November
                        return day <= 30;
                    default: // January, March, May, July, August, October, December
                        return day <= 31;
                }
            }
        }
    }
    return false;
}
bool isValidValue(const std::string& valueStr, float& value)
{
    std::istringstream ss(valueStr);
    if (ss >> value && value >= 0 && value <= 1000)
        return true;
    return false;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange("data.csv");
   // BitcoinExchange btcExchange("data2.csv");
   /*
   std::cout << "IMPRIMIMOS MAPA: " << std::endl;
   btcExchange.printMap();
   std::cout << std::endl;
   */

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cout << "Error: could not open file: " << argv[1] << std::endl;
        return 1;
    }

    std::string line;
    if (!getline(inputFile, line))
    {
        std::cout << "Error: file is empty or cannot read header." << std::endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        getline(ss, date, '|');
        getline(ss, valueStr);
        date.erase(date.find_last_not_of(" \n\r\t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

        float value;
        if (!isValidDate(date)) 
            std::cout << "Error: bad input => " << date << std::endl;
        else if (!isValidValue(valueStr, value)) 
        {
            if (value < 0)
                std::cout << "Error: not a positive number" << std::endl;
            else
                std::cout << "Error: too large a number" << std::endl;
        }
        else 
        {
            float rate = btcExchange.getExchangeRate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
    }

    return 0;
}
