#include "RPN.hpp"

rpn::rpn() {}

rpn::rpn(const rpn &rhs)
{
    *this = rhs;
}

rpn &rpn::operator=(const rpn &rhs)
{
    _stack = rhs._stack;
    return (*this);
}

rpn::~rpn() {}

void rpn::calculator(char c)
{
    double operand1;
    double operand2;

    if (_stack.size() > 1)
    {
        operand2 = _stack.top(); _stack.pop();
        operand1 = _stack.top(); _stack.pop();
        int sign = static_cast<int>(c);
        switch (sign)
        {
            case 42:
                _stack.push(operand1 * operand2);
                break ;

            case 43:
                _stack.push(operand1 + operand2);
                break ;

            case 45:
                _stack.push(operand1 - operand2);
                break ;

            case 47:
                if (operand2 == 0)
                    throw DivisionByZero();
                _stack.push(operand1 / operand2);
                break ;
        }
    }
    else
        throw NotEnoughNumbers();
}

void rpn::initStack(std::string str)
{
    std::string::iterator it = str.begin();
    std::string::iterator it2 = str.end();

    while (it != it2)
    {
        if (isdigit(*it))
            _stack.push(*it - '0');
        else if (*it != ' ')
            calculator(*it);
        it++;
    }
    if (_stack.size() != 1)
        throw StackTooLarge();
    else
        std::cout << "result: " << _stack.top() << std::endl;
}
