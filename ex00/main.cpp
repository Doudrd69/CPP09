#include "BitcoinExchange.hpp"
#include <iostream>

std::string displayExchangeRate(float rate, std::pair<std::string, float> & line_values) {
    std::cout << line_values.first << " => " << line_values.second << " = " << line_values.second * rate << std::endl;
}

int main(int ac, char **av) {
    std::ifstream input(av[1]);
    std::string buf;

    if (input.is_open()) {
        std::cout << "File not found" << std::endl;
        return -1;
    }

    BitcoinExchange exchange_db;

    getline(input, buf);
    while (getline(input, buf)) {
        std::pair<std::string, float> line_values;
        try {
            line_values = parse_txt(buf);
            displayExchangeRate(exchange_db.getRate(line_values.first), line_values);
        } catch(CoinIsOutOfRange &e) {
            std::cerr << << e.what() << '\n';
        }
    }
}