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
    void calculator(char c);

};

class Exception: public std::exception
{
    protected:
        std::string msg;
    public:
        Exception() {
            this->msg = "Exception : ";
        }

        Exception(std::exception exception) {
            this->msg = exception.what() + msg;
        }

        ~Exception()throw(){};

        virtual char const * what() const throw() {
            return msg.c_str();
        };
};

/* PARSING EXCEPTION */

class ArgInvalid : public Exception
{   public:
        ArgInvalid() {
            this->msg += "Argument is invalid : ";
        }
};

class EmptyString : public ArgInvalid
{   public:
        EmptyString() {
            this->msg += "empty string";
        }
};

class InvalidChar : public ArgInvalid
{   public:
        InvalidChar() {
            this->msg += "invalid char detected";
        }
};

class NoOperator : public ArgInvalid
{   public:
        NoOperator() {
            this->msg += "no operator detected";
        }
};

class NoOperatorBetweenNumbers : public ArgInvalid
{   public:
        NoOperatorBetweenNumbers() {
            this->msg += "no operator between numbers";
        }
};

class SpaceAtTheEnd : public ArgInvalid
{   public:
        SpaceAtTheEnd() {
            this->msg += "space at the end";
        }
};

class LastCharIsNotOperator : public ArgInvalid
{   public:
        LastCharIsNotOperator() {
            this->msg += "last char must be an operator";
        }
};

class NoSpaceBetweenElements : public ArgInvalid
{   public:
        NoSpaceBetweenElements() {
            this->msg += "no space between elements";
        }
};

/* EXECUTION EXCEPTION */

class ExecException : public Exception
{   public:
        ExecException() {
            this->msg += "Calcul failed : ";
        }
};

class DivisionByZero : public ExecException
{   public:
        DivisionByZero() {
            this->msg += "divison by 0 is impossible";
        }
};

class NotEnoughNumbers : public Exception
{   public:
        NotEnoughNumbers() {
            this->msg += "not enough numbers left to calculate";
        }
};

class StackTooLarge : public Exception
{   public:
        StackTooLarge() {
            this->msg += "more than one number in the end";
        }
};

#endif