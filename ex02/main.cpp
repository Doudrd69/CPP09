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
            std::cerr << "error: input underflow" << std::endl;
        else
            std::cerr << "error: input overflow" << std::endl;
        return (-1);
    }
    return (0);
}

void    parse_args(int ac, char **av)
{
    if (check_duplicate_numbers(ac, av) == -1)
    {
        std::cerr << "error: You cannot have a duplicate" << std::endl;
        return ;
    }
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
            {
                std::cerr << "error: invalid input detected -> [" << av[i][j] << "]" << std::endl;
                return ;
            }
            else
                j++;
        }
        inst.set(atoi(av[i]));
        i++;
    }
    std::cout << "vector: ";
    printVector(inst.getVector());
    std::cout << "deque: ";
    printDeque(inst.getDeque());
    std::cout << "\nSorted containers: " << std::endl;

    std::vector<int> tmp_vector(inst.getVector());
    std::deque<int> tmp_deque(inst.getDeque());

    vectorMergeSort(tmp_vector, 0, inst.getVector().size() - 1, inst.getVector().size() / 2);
    std::cout << "sorted vector: ";
    printVector(tmp_vector);


    dequeMergeSort(tmp_deque, 0, inst.getDeque().size() - 1, inst.getDeque().size() / 2);
    std::cout << "sorted deque: ";
    printDeque(tmp_deque);
}

int main(int ac, char **av)
{
    if (ac < 1)
    {
        std::cerr << "Usage: ./PmergeMe [list of integers]" << std::endl;
        return (-1);
    }
    parse_args(ac, av);
}