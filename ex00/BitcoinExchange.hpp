#pragma once
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

void isDateValid(std::string & date) {
}

float isCoinValid(std::string value) {

    char    *end;

    long int    int_input = std::strtol(value.c_str(), &end, 10);
    if (int_input > 1000)
        throw CoinUpperBound();
    if (int_input < 0)
        throw CoinLowerBound();
    if (*end == 0)
        return (static_cast<float>(int_input));

    float       float_input = std::strtof(value.c_str(), &end);
    if (float_input > 1000)
        throw CoinUpperBound();
    if (float_input < 0)
        throw CoinLowerBound();
    if (*end == 0)
        return (float_input);

    throw std::invalid_argument("Error : non-numerical value : ");
}

std::pair<std::string, float> parse_txt(std::string & input)
{
    size_t delimiter_index = input.find(" | ");
    if (delimiter_index == std::string::npos)
        throw std::out_of_range("Error : no delimiter \" | \"");

    std::string date = input.substr(0, delimiter_index);
    std::string coin = input.substr(delimiter_index + 3, input.size() - delimiter_index);

    try {
        isDateValid(date);
        float valid_coin = isCoinValid(coin);
        return std::make_pair(date, valid_coin);
    }
    catch(const std::exception& e) {
        throw e;
    }
}

class Exception: public std::exception
{
    public:
        Exception() {
            this->msg = "Ecxeption : ";
        }

        Exception(std::exception exception) {
            this->msg = exception.what() + msg;
        }

        virtual ~Exception() noexcept {}

        virtual const char* what() const noexcept {
            return msg.c_str();
        }
    protected:
        std::string msg;
};

class CoinIsOutOfRange : public Exception
{   public:
        CoinIsOutOfRange() {
            this->msg += "Coin value is out of range : ";
        }
};
class CoinLowerBound : CoinIsOutOfRange
{   public:
        CoinLowerBound() {
            this->msg += "value is negative";
        }
};
class CoinUpperBound : CoinIsOutOfRange
{   public:
        CoinUpperBound() {
            this->msg += "value is more than 1000";
        }
};

class BitcoinExchange
{
private:
    std::map<std::string, float> data;

public:


    BitcoinExchange();
    ~BitcoinExchange();

    void printMap();
    float getRate(std::string & key);
};

BitcoinExchange::BitcoinExchange()
{
    std::ifstream database("data.csv");
    std::string key;
    std::string value;
    float       nb;
    size_t  delim;

    if (!database.is_open())
    {
        std::cerr << "Input file is not valid" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (getline(database, key))
    {
        if (key != "date,exchange_rate")
        {
            delim = key.find(',');
            std::stringstream ssnb;
            value = key.substr(delim + 1, key.size() - delim);
            ssnb << value;
            ssnb >> nb;
            data[key.substr(0, delim - 1)] = nb;
        }
    }
}

void BitcoinExchange::printMap()
{
    std::map<std::string, float>::iterator end = data.end();

    for (std::map<std::string, float>::iterator it = data.begin(); it != end; it++)
    {
        std::cout << it->first;
        std::cout << " | ";
        std::cout << it->second;
        std::cout <<  std::endl;
    }
}

float BitcoinExchange::getRate(std::string & key) {

    //  key > data.lastkey (reverse begin is the last element) || key < data.firstkey
    if (key > this->data.rbegin()->first || key < this->data.begin()->first)
        throw std::out_of_range("Error : Unknown value for this key");

    return this->data.lower_bound(key)->second;
}

BitcoinExchange::~BitcoinExchange()
{
}