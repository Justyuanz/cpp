#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _rates;
    std::map<std::string, double> _input;


public:
    BitcoinExchange() = default;
    BitcoinExchange(const BitcoinExchange &other) = default;
    BitcoinExchange &operator=(const BitcoinExchange &other) = default;
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
    bool isValidFormat(const std::string& date);

};
