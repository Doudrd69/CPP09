#include <iostream>
#include <exception>

void    parse_rnp(std::string rnp) {

    // if (rnp.find_first_of("+-/*") != rnp.npos)
    //     throw error;
    if (rnp.find_first_not_of("0123456789+-*/ ") != rnp.npos)
        throw std::exception();
}

int main(int ac, char **av) {

    if (ac == 2)
    {
        //parser la RPN --> chiffres < 10 && seulement les opérateurs " + - * / "
        try
        {
            parse_rnp(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        //execution du calcul grace à une stack
    }
    return 1;
}