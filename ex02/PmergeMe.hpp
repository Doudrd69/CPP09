#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <iterator>
#include <limits.h>
#include <cstring>

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

#endif