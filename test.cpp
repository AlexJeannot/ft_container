#include <iostream>
#include <vector>

int main()
{
    std::vector<int>v;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    std::cout << "-------" << std::endl;

    v.insert(v.begin(), 12, 12);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    std::cout << "-------" << std::endl;
    v.insert(v.begin(), 1, 12);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    std::cout << "-------" << std::endl;
    v.insert(v.begin(), 15, 12);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    std::cout << "-------" << std::endl;
    v.resize(10);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    std::cout << "-------" << std::endl;
    v.resize(50);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    std::cout << "-------" << std::endl;
    v.resize(150);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    std::cout << "-------" << std::endl;
    v.resize(1500);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
}