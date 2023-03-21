#include "PmergeMe.hpp"

void vectorMergeSort(std::vector<int> &arr, int begin, int end, int mid_size);
void vectorMerge(std::vector<int> &arr, int begin, int middle, int end);
void dequeMergeSort(std::deque<int> &arr, int begin, int end, int mid_size);
void dequeMerge(std::deque<int> &arr, int begin, int middle, int end);

void    printVector(std::vector<int> const &input)
{
    std::copy(input.begin(), input.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void    printDeque(std::deque<int> const &input)
{
    std::copy(input.begin(), input.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int	check_duplicate_numbers(int ac, char **av)
{
    int i;
    int j;
    int len;

    i = 1;
    while (i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if (strlen(av[i]) > strlen(av[j]))
                len = strlen(av[i]);
            else
                len = strlen(av[j]);
            if (strncmp(av[i], av[j], len) == 0)
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_int(char *av)
{
    long	nb;

    nb = atol(av);
    if (nb < INT_MIN || nb > INT_MAX)
    {
        if (nb < INT_MIN)
            throw Underflow();
        else
           throw Overflow();
        return (-1);
    }
    return (0);
}

void    printAndSort(PmergeMe &inst)
{
    std::cout << "vector: ";
    printVector(inst.getVector());
    std::cout << "deque: ";
    printDeque(inst.getDeque());

    std::vector<int> tmp_vector(inst.getVector());
    std::deque<int> tmp_deque(inst.getDeque());

    struct timeval startVec, endVec;
    double execTimeVec;

    gettimeofday(&startVec, NULL);
    vectorMergeSort(tmp_vector, 0, inst.getVector().size() - 1, inst.getVector().size() / 2);
    gettimeofday(&endVec, NULL);
    execTimeVec = static_cast<double>((endVec.tv_sec - startVec.tv_sec) * 1000000 + (endVec.tv_usec - startVec.tv_usec));
    std::cout << "sorted vector: ";
    printVector(tmp_vector);

    struct timeval startDeque, endDeque;
    double execTimeDeque;

    gettimeofday(&startDeque, NULL);
    dequeMergeSort(tmp_deque, 0, inst.getDeque().size() - 1, inst.getDeque().size() / 2);
    gettimeofday(&endDeque, NULL);
    execTimeDeque = static_cast<double>((endDeque.tv_sec - startDeque.tv_sec) * 1000000 + (endDeque.tv_usec - startDeque.tv_usec));
    std::cout << "sorted deque: ";
    printDeque(tmp_deque);

    std::cout << "Time to process a range of " << inst.getVector().size() << " elements with std::vector : " << execTimeVec << " µs" << std::endl;
    std::cout << "Time to process a range of " << inst.getDeque().size() << " elements with std::deque : " << execTimeDeque << " µs" << std::endl;
}

void    parse_args(int ac, char **av)
{
    if (check_duplicate_numbers(ac, av) == -1)
        throw Duplicate();
    int i = 1;
    PmergeMe inst;
    while (av[i])
    {
        if (check_int(av[i]) == -1)
            return ;
        int j = 0;
        while (av[i][j])
        {
            if (!isdigit(av[i][j]))
                throw InvalidInput();
            else
                j++;
        }
        inst.set(atoi(av[i]));
        i++;
    }
    printAndSort(inst);
}

int main(int ac, char **av)
{
    if (ac < 1)
    {
        std::cerr << "Usage: ./PmergeMe [list of integers]" << std::endl;
        return (-1);
    }
    try
    {
        parse_args(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}