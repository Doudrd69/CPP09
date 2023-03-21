#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
#include <iterator>
#include <limits.h>
#include <cstring>

class PmergeMe
{
private:

    std::vector<int> _vector;
    std::list<int> _list;

public:

    PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();

    void set(int nb);
    void vectorMergeSort(std::vector<int> &arr, int left, int right);
    void vectorMerge(std::vector<int> &arr, int left, int middle, int right);
    std::vector<int> getVector();
    std::list<int> getList();
};

#endif