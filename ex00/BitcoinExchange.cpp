#include "BitcoinExchange.hpp"

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

    std::map<std::string, float>::iterator it = data.find(key);

    std::cout << this->data.lower_bound(key)->second << std::endl;

    if (it != data.end())
        return it->second;
    else
        return this->data.lower_bound(key)->second;
}

BitcoinExchange::~BitcoinExchange() {}
