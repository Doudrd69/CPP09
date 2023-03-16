#pragma once
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

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

        ~Exception() _NOEXCEPT {};

        virtual char const * what() const throw() {
            return msg.c_str();
        };
};

class ParsingFormat : public Exception {
    public:
        ParsingFormat() {
            this->msg += "Input format invalid\n";
        }
};

class CoinIsOutOfRange : public Exception
{   public:
        CoinIsOutOfRange() {
            this->msg += "Coin value is out of range : ";
        }
};
class CoinLowerBound : public CoinIsOutOfRange
{   public:
        CoinLowerBound() {
            this->msg += "value is negative \n";
        }
};
class CoinUpperBound : public CoinIsOutOfRange
{   public:
        CoinUpperBound() {
            this->msg += "value is more than 1000.0 \n";
        }
};

class DateIsInvalid : public Exception
{
    public:
        DateIsInvalid() {
            this->msg += "Date is invalid : ";
        }
};

class DateWrongFormat : public DateIsInvalid
{
    public:
        DateWrongFormat() {
            this->msg += "error in date format \n";
        }
};

class DateDayInvalid : public DateIsInvalid
{
    public:
        DateDayInvalid() {
            this->msg += "day date is invalid \n";
        }
};

class DateHasNonNumericChar : public DateIsInvalid
{
    public:
        DateHasNonNumericChar() {
            this->msg += "non numeric char detected \n";
        }
};

class BitcoinExchange
{
private:
    std::map<std::string, float> data;
public:


    BitcoinExchange();
    ~BitcoinExchange();

    void    printMap();
    float   getRate(std::string & key);
};