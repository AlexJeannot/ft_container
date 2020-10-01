#include <iostream>
#include <vector>

int main()
{
    std::vector<int>v;
    std::vector<int>v2;

    std::cout << "-------" << std::endl;
    v.reserve(10);
    v2.reserve(11);
    std::cout << (v == v2) << std::endl;
    v.reserve(11);
    std::cout << (v == v2) << std::endl;
    v.push_back(1);
    std::cout << (v == v2) << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "v size sup " << (v < v2) << std::endl;
    v2.push_back(1);
    std::cout << "v size equal " << (v < v2) << std::endl;
    v2.push_back(2);
    std::cout << "v2 size sup " << (v < v2) << std::endl;
    v.push_back(1);
    std::cout << "v size equal v2 sup " << (v < v2) << std::endl;
    std::cout << "================" << std::endl;
    for (auto x : v)
        std::cout << x << std::endl;
    v.resize(5);
    std::cout << "-------" << std::endl;
    for (auto x : v)
        std::cout << x << std::endl;


}