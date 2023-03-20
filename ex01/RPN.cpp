#include "RPN.hpp"

rpn::rpn()
{
}

rpn::rpn(const rpn &rhs)
{
    *this = rhs;
}

rpn &rpn::operator=(const rpn &rhs)
{
    _stack = rhs._stack;
    return (*this);
}

rpn::~rpn()
{
}

void rpn::whichOperator(char c)
{
    int operand1;
    int operand2;

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
                {
                    std::cerr << "error: cannot divide by 0" << std::endl;
                    return ;
                }
                _stack.push(operand1 / operand2);
                break ;
        }
    }
    else
    {
        std::cerr << "not enough numbers" << std::endl;
        return ;
    }
}

void rpn::calculate(std::string str)
{
    std::string::iterator it = str.begin();
    std::string::iterator it2 = str.end();

    while (it != it2)
    {
        if (isdigit(*it))
            _stack.push(*it - '0');
        else if (*it != ' ')
            whichOperator(*it);
        it++;
    }
    if (_stack.size() != 1)
    {
        std::cerr << "error: More than one element" << std::endl;
        return ;
    }
    else
        std::cout << "result: " << _stack.top() << std::endl;
}
