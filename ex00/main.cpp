#include "BitcoinExchange.hpp"
#include <iostream>


float isCoinValid(std::string value) {

    char    *end;

    int i = 0;
    while (value[i] == ' ')
        i++;
    if (value[i] <= 58 || value[i] >= 48)
    {
        while (value[i])
        {
            if (value[i] == ' ')
                throw WrongValueFormat();
            i++;
        }

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
    } 
    throw NonNumericalValuet();
}

int  countChar(std::string str, char c)
{
    int count = 0;

    std::string::iterator it = str.begin();
    while (it != str.end())
    {
        if (*it == c)
            count++;
        it++;
    }
    return (count);
}

bool isNumeric(std::string &str)
{
    std::string::iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

void checkDate(int date, int i, int j)
{
    if (date < i || date > j)
        throw DateDayInvalid();
}

void  isDateValid(std::string key)
{
    if (countChar(key, '-') != 2)
        throw DateWrongFormat();

    int delimiter = key.find('-');
    int delimiter2 = key.rfind('-');
    std::string y = key.substr(0, delimiter);
    std::string m = key.substr(delimiter + 1, delimiter2 - delimiter - 1);
    std::string d = key.substr(delimiter2 + 1, key.size());

    if (!isNumeric(y) || !isNumeric(d) || !isNumeric(m))
        throw DateHasNonNumericChar();

    int year = atoi(y.c_str());
    int day = atoi(d.c_str());
    int month = atoi(m.c_str());

    if (month < 1 || month > 12)
        throw DateIsInvalid();
    if ((month % 2 == 0) && month != 2 && month != 8){
        checkDate(day, 1, 30);
    }
    if ((month % 2 != 0)){
        checkDate(day, 1, 31);
    }
    if ((year % 4 == 0) && month == 2){
        checkDate(day, 1, 29);
    }
    if ((year % 4 != 0) && month == 2)
        checkDate(day, 1, 28);
}


void displayExchangeRate(float rate, std::pair<std::string, float> & line_values) {
    std::cout << line_values.first << " => " << line_values.second << " = " << line_values.second * rate << std::endl;
}

std::pair<std::string, float> parse_txt(std::string & input)
{
    size_t delimiter_index = input.find(" | ");
    if (delimiter_index == std::string::npos)
        throw ParsingFormat();

    std::string date = input.substr(0, delimiter_index);
    std::string coin = input.substr(delimiter_index + 3, input.size() - delimiter_index);

    isDateValid(date);
    float valid_coin = isCoinValid(coin);

    return std::make_pair(date, valid_coin);
}

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

int main(int ac, char **av) {
    
    if (ac == 2)
    {
        std::ifstream input(av[1]);
        std::string buf;

        if (!input.is_open()) {
            std::cout << "File not found" << std::endl;
            return -1;
        }

        if (is_empty(input)) {
            std::cout << "Empty file" << std::endl;
            return -1;
        }

        BitcoinExchange exchange_db;

        getline(input, buf);
        while (getline(input, buf)) {
            std::pair<std::string, float> line_values;
            try {
                line_values = parse_txt(buf);
                displayExchangeRate(exchange_db.getRate(line_values.first), line_values);
            } catch(Exception &e) {
                std::cerr << e.what() << " -> " << buf << std::endl;
            }
        }
    }
}