/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:34:54 by javi              #+#    #+#             */
/*   Updated: 2024/07/03 17:34:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &database);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange &other);
        
        float getExchangeRate(const std::string& date) const;
        void printMap(void) const;

    private:
        std::map<std::string, float> exchangeRates;
        void loadDatabase(const std::string& database);
        void clearDatabase();
};

#endif
