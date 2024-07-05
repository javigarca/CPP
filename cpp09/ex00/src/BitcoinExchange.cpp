/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:35:04 by javi              #+#    #+#             */
/*   Updated: 2024/07/03 17:35:06 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>


BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const std::string& database)
{
    loadDatabase(database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        clearDatabase();
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    clearDatabase();
}

void BitcoinExchange::loadDatabase(const std::string& database)
{
    std::ifstream file(database.c_str());
    if (!file)
    {
        std::cout << "Error: could not open database: " << database << std::endl;
        return;
    }

    std::string line;
    
    if (!getline(file, line))
    {
        std::cout << "Error: file is empty or cannot read header." << std::endl;
        return;
    }

    std::string date;
    float rate;
    while (getline(file, line))
    {
        std::istringstream ss(line);
        if (getline(ss, date, ',') && ss >> rate)
            exchangeRates[date] = rate;
    }
}

void BitcoinExchange::clearDatabase()
{
    exchangeRates.clear();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first != date)
    {
        if (it == exchangeRates.begin())
            return 0.0f; // No earlier date found
        --it;
    }
    return it->second;
}

void BitcoinExchange::printMap() const
{
    std::map<std::string, float>::const_iterator it = exchangeRates.begin();
    while (it != exchangeRates.end())
    {
        std::cout << "Date: " << it->first << " | Value: " << it->second << std::endl;
        ++it;
    }
}

