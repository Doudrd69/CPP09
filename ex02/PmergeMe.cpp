#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
    *this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    _vector = rhs._vector;
    _list = rhs._list;
    return (*this);
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::set(int nb)
{
    _vector.push_back(nb);
    _list.push_back(nb);
}

std::vector<int> PmergeMe::getVector()
{
    return (_vector);
}

std::list<int> PmergeMe::getList()
{
    return (_list);
}