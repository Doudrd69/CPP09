#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) {

    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {

    this->_vector = obj._vector;
    this->_list = obj._list;
    return *this;
}

PmergeMe::~PmergeMe() {}

void    vectorMerge(std::vector<int> &arr, int left, int middle, int right) {

    int left_size = middle - left + 1;
    int right_size = right - middle;

    std::vector<int> tmp_left(left_size);
    std::vector<int> tmp_right(right_size);

    for (int i = 0; i < left_size; i++)
        tmp_left[i] = arr[left + i];

    for (int i = 0; i < right_size; i++)
        tmp_right[i] = arr[middle + 1 + i];

    int i, j, k;

    i = 0, j = 0, k = left;

    while (i < left_size && j < right_size)
    {
        if (tmp_left[i] <= tmp_right[j]) {
            arr[k] = tmp_left[i];
            i++;
        }
        else {
            arr[k] = tmp_right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        arr[k] = tmp_left[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        arr[k] = tmp_right[j];
        j++;
        k++;
    }

    return ;
}

void    vectorMergeSort(std::vector<int> &arr, int left, int right) {

    if (left >= right)
        return ;

    int middle = (left + right) / 2;

    vectorMergeSort(arr, left, middle);
    vectorMergeSort(arr, middle + 1, right);

    vectorMerge(arr, left, middle, right);
}

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