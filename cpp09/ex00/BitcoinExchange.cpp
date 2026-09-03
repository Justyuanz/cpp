#include "BitcoinExchange.hpp"

#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>

BitcoinExchange::~BitcoinExchange()
{

}

bool BitcoinExchange::isValidFormat(const std::string& date)
{
    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (std::size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31};

    bool leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);

    if (leap)
        daysInMonth[1] = 29;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > daysInMonth[month - 1])
        return false;


    return true;
}
void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    std::string date;
    std::string amount;
    getline(file, line);

    // Validate and calculate every input record.
    while (getline(file, line))
    {
        std::size_t pipe = line.find('|');
        if (pipe == line.npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (line.find('|', pipe + 1) != std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (pipe == 0 ||
            pipe + 1 >= line.size() ||
            line[pipe - 1] != ' ' ||
            line[pipe + 1] != ' ')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, pipe - 1);
        amount = line.substr(pipe + 2, line.size() - (pipe + 2));
        if (!isValidFormat(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double d_amount;
        std::size_t pos;
        try
        {
            d_amount = std::stod(amount, &pos);
        }
        catch (...)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (pos != amount.size())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!std::isfinite(d_amount))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (d_amount < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (d_amount > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Use the exact rate or the closest earlier date.
        std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
        if (date < _rates.begin()->first)
        {
            std::cerr << "Error: input date too early" << std::endl;
            continue;
        }
        if (it == _rates.end() || it->first != date)
            it--;

        //calculate
        double result = d_amount * it->second;
        std::cout << date << " => " << d_amount << " = " << result << std::endl;
    }
    file.close();
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::string date;
    std::string rate;
    getline(file, line);

    while (getline(file, line))
    {
        std::size_t comma = line.find(',');
        date = line.substr(0, comma);
        rate = line.substr(comma + 1, line.size() - (comma + 1));
        double d_rate = std::stod(rate);
        _rates[date] = d_rate;
    }
    file.close();
}
