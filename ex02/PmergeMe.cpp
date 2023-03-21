#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

    this->_vector.push_back(4);
    this->_vector.push_back(1);
    this->_vector.push_back(9);
    this->_vector.push_back(6);

    int array_size = this->_vector.size();

    std::cout << "Unsorted array : " << std::endl;
    for (int i = 0; i < array_size; i++)
        std::cout << this->_vector[i] << " - ";
    std::cout << "\n\n=============" << std::endl;

    vectorMergeSort(this->_vector, 0, array_size - 1);

    std::cout << "\nSorted array : " << std::endl;
    for (int i = 0; i < array_size; i++)
        std::cout << this->_vector[i] << " - ";
}

PmergeMe::PmergeMe(const PmergeMe& obj) {

    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {

    this->_vector = obj._vector;
    this->_list = obj._list;
    return *this;
}

void    PmergeMe::vectorMerge(std::vector<int> &arr, int left, int middle, int right) {

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

PmergeMe::~PmergeMe() {}

void    PmergeMe::vectorMergeSort(std::vector<int> &arr, int left, int right) {

    if (left >= right)
        return ;

    int middle = (left + right) / 2;

    vectorMergeSort(arr, left, middle);
    vectorMergeSort(arr, middle + 1, right);

    vectorMerge(arr, left, middle, right);
}