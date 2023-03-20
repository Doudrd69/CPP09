#include <iostream>
#include <exception>
#include "RPN.hpp"

bool operator_check(std::string::iterator it) {

    if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        return (true);
    return (false);
}

void    parse_rnp(std::string rnp) {

    // 8 9 8 4 + ...
    if (rnp.empty())
        throw "Error : empty string";

    if (rnp.find_first_not_of("123456789+-*/ ") != rnp.npos)
        throw "Error : invalid char detected";

    std::size_t _operator = rnp.find_first_of("+-*/");
    if (_operator == std::string::npos)
        throw "Error : no operator detected";

    for (std::size_t i = _operator; i < rnp.size(); i++)
    {
        if ((i <= '9' && i >= '0') && ((i + 2) != '+'))
            throw "Error : no operator between numbers";
    }

    for(std::string::iterator it = rnp.begin(); it != rnp.end(); ++it)
    {
        std::cout << *it << std::endl;
        if ((*it == ' ' && it == rnp.end() - 1))
            throw "Error : space at the end of RNP";
        if ((it == rnp.end() - 1) && operator_check(it) == false)
            throw "Error : last char should be an operator";
        if ((*it <= '9' && *it >= '0') && (*(it + 1) != ' ') && it != rnp.end() - 1)
            throw "Error : no space between elements";
    }
    return ;
}

int main(int ac, char **av) {

    if (ac == 2)
    {
        try
        {
            parse_rnp(av[1]);
            //execution du calcul grace à une stack
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cerr << "Usage: ./RPN [numbers and operations]" << std::endl;
        return -1;
    }
    return 1;
}