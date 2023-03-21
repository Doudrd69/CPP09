#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <iterator>
#include <limits.h>
#include <cstring>
#include <sys/time.h>
#include <time.h>

class PmergeMe
{
private:

    std::vector<int> _vector;
    std::deque<int> _deque;

public:

    PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();

    void set(int nb);
    std::vector<int> getVector();
    std::deque<int> getDeque();
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

class Underflow : public ArgInvalid
{   public:
        Underflow() {
            this->msg += "input underflow";
        }
};

class Overflow : public ArgInvalid
{   public:
        Overflow() {
            this->msg += "input overflow";
        }
};

class Duplicate : public ArgInvalid
{   public:
        Duplicate() {
            this->msg += "duplicate impossible";
        }
};

class InvalidInput : public ArgInvalid
{   public:
        InvalidInput() {
            this->msg += "invalid input detected";
        }
};


#endif