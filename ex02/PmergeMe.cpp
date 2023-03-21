#include "PmergeMe.hpp"

/* == CLASS CONSTRUCTORS == */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) {

    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {

    this->_vector = obj._vector;
    this->_deque = obj._deque;
    return *this;
}

PmergeMe::~PmergeMe() {}

/* == VECTOR MERGE-INSERT-SORT == */

void    vectorInsertionSort(std::vector<int> &arr, int begin, int end) {

    for (int i = begin; i < end; i++) {
        int tmp = arr[i + 1];
        int j = i + 1;
        while (j > begin && arr[j - 1] > tmp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
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
        vectorInsertionSort(arr, begin, end);
}

/* == DEQUE MERGE-INSERT-SORT == */

void    dequeInsertionSort(std::deque<int> &arr, int begin, int end) {

    for (int i = begin; i < end; i++) {
        int tmp = arr[i + 1];
        int j = i + 1;
        while (j > begin && arr[j - 1] > tmp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
    }
}

void    dequeMerge(std::deque<int> &arr, int begin, int middle, int end) {

    int left_size = middle - begin + 1;
    int right_size = end - middle;

    std::deque<int> tmp_left(left_size);
    std::deque<int> tmp_right(right_size);

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

void    dequeMergeSort(std::deque<int> &arr, int begin, int end, int mid_size) {


    if (end - begin > mid_size)
    {
        int middle = (begin + end) / 2;

        dequeMergeSort(arr, begin, middle, mid_size);
        dequeMergeSort(arr, middle + 1, end, mid_size);
        dequeMerge(arr, begin, middle, end);
    }
    else
        dequeInsertionSort(arr, begin, end);
}

/* == CLASS UTILS == */

void PmergeMe::set(int nb)
{
    _vector.push_back(nb);
    _deque.push_back(nb);
}

std::vector<int> PmergeMe::getVector()
{
    return (_vector);
}

std::deque<int> PmergeMe::getDeque()
{
    return (_deque);
}