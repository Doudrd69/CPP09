#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <iterator>

class rpn
{
private:

    std::stack<int> _stack;

public:

    rpn();
    rpn(const rpn &rhs);
    rpn &operator=(const rpn &rhs);
    ~rpn();

    void initStack(std::string str);
};

#endif