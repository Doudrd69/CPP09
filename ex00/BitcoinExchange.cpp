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
            data[key.substr(0, delim)] = nb;
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {

    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {

    this->data = obj.data;
    return *this;
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
    if (key > this->data.rbegin()->first)
        throw TooRecentDate();
    else if (key < this->data.begin()->first)
        throw TooOldDate();

    std::map<std::string, float>::iterator it = data.find(key);

    if (it != data.end()) {
        return it->second;
    } else {
        // return data[I] where I is the first value >= key
        it = this->data.lower_bound(key);

        // to get the previous value
        it--;
        
        return it->second;
    }
}

BitcoinExchange::~BitcoinExchange() {}
