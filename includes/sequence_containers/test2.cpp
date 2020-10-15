#include "test.hpp"
#include "../includes/sequence_containers/Vector.hpp"

#define OK "\033[38;5;40mOK\033[0m"
#define KO "\033[38;5;124mKO\033[0m"

void fOK(std::string test)
{
    std::cout << OK << "\033[38;5;43m >> " << test << "\033[0m" << std::endl;
}

void fKO(std::string test)
{
    std::cout << KO << "\033[38;5;43m >> " << test << "\033[0m" << std::endl;
}

int main()
{
    ft::Vector<int> v1;
    v1.push_back(1);
    ft::Vector<int> v2(v1);


    return (0);
}