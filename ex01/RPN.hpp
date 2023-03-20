#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <stdlib.h>

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
    void printStack();
    void calculate(std::string str);
    void whichOperator(char c);

};

#endif