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

void    insertionSort(std::vector<int> &arr, int begin, int end) {

    for (int i = begin; i < end; i++) {
        int tempVal = arr[i + 1];
        int j = i + 1;
        while (j > begin && arr[j - 1] > tempVal) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tempVal;
    }
}

void    vectorMerge(std::vector<int> &arr, int begin, int middle, int end) {

    int left_size = middle - begin + 1;
    int right_size = end - middle;

    std::vector<int> tmp_left(left_size);
    std::vector<int> tmp_right(right_size);

    for (int i = 0; i < left_size; i++)
        tmp_left[i] = arr[begin + i];

    for (int i = 0; i < right_size; i++)
        tmp_right[i] = arr[middle + 1 + i];

    int i, j, k;

    i = 0, j = 0, k = begin;

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

void    vectorMergeSort(std::vector<int> &arr, int begin, int end, int mid_size) {


    if (end - begin > mid_size)
    {
        int middle = (begin + end) / 2;

        vectorMergeSort(arr, begin, middle, mid_size);
        vectorMergeSort(arr, middle + 1, end, mid_size);

        vectorMerge(arr, begin, middle, end);
    }
    else
        insertionSort(arr, begin, end);

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