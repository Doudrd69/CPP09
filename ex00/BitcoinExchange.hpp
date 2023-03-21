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

        ~Exception()throw(){};

        virtual char const * what() const throw() {
            return msg.c_str();
        };
};

class ParsingFormat : public Exception {
    public:
        ParsingFormat() {
            this->msg += "Input format invalid";
        }
};

class WrongValueFormat : public ParsingFormat {
    public:
        WrongValueFormat() {
            this->msg += " : more than one value detected";
        }
};

class NonNumericalValuet : public ParsingFormat {
    public:
        NonNumericalValuet() {
            this->msg += " : non-numerical value detected";
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
            this->msg += "value is negative";
        }
};
class CoinUpperBound : public CoinIsOutOfRange
{   public:
        CoinUpperBound() {
            this->msg += "value is more than 1000.0";
        }
};

class DateIsInvalid : public Exception
{
    public:
        DateIsInvalid() {
            this->msg += "Date doesn't exist";
        }
};

class DateWrongFormat : public DateIsInvalid
{
    public:
        DateWrongFormat() {
            this->msg += "error in date format";
        }
};

class DateDayInvalid : public DateIsInvalid
{
    public:
        DateDayInvalid() {
            this->msg += "day date is invalid";
        }
};

class DateHasNonNumericChar : public DateIsInvalid
{
    public:
        DateHasNonNumericChar() {
            this->msg += "non numeric char detected";
        }
};

class BitcoinExchange
{
private:
    std::map<std::string, float> data;
public:


    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);
    ~BitcoinExchange();

    void    printMap();
    float   getRate(std::string & key);

    class TooRecentDate : public Exception {
        public:
            TooRecentDate() {
                this->msg += "the date is too recent";
            }
    };

    class TooOldDate : public Exception {
        public:
            TooOldDate() {
                this->msg += "the date is too old";
            }
    };
};