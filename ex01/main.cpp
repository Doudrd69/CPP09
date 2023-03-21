#include "RPN.hpp"

bool operator_check(std::string::iterator it) {

    if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        return (true);
    return (false);
}

std::string parse_rnp(std::string rnp) {

    if (rnp.empty())
        throw EmptyString();
    if (rnp.find_first_not_of("0123456789+-*/ ") != rnp.npos)
        throw InvalidChar();
    std::size_t _operator = rnp.find_first_of("+-*/");
    if (_operator == std::string::npos)
        throw NoOperator();
    for (std::size_t i = _operator; i < rnp.size(); i++)
    {
        if ((i <= '9' && i >= '0') && ((i + 2) != '+'))
            throw NoOperatorBetweenNumbers();
    }
    for(std::string::iterator it = rnp.begin(); it != rnp.end(); ++it)
    {
        if ((*it == ' ' && it == rnp.end() - 1))
            throw SpaceAtTheEnd();
        if ((it == rnp.end() - 1) && operator_check(it) == false)
            throw LastCharIsNotOperator();
        // if ((*it <= '9' && *it >= '0') && (*(it + 1) != ' ') && it != rnp.end() - 1)
        //     throw NoSpaceBetweenElements();
    }
    return (rnp);
}

int main(int ac, char **av) {

    if (ac == 2)
    {
        try
        {
            rpn rpn;
            rpn.initStack(parse_rnp(av[1]));
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