#include <iostream>
#include <vector>
#include <list>
#include "includes/sequence_containers/List.hpp"

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

    std::cout << "================" << std::endl;

    std::list<int> li;
    for (int count = 0; count < 10; count++)
        li.push_back(count);
    
    for (std::list<int>::iterator it = li.begin(); it != li.end(); it++)
        std::cout << *it << std::endl;

    std::list<int>::iterator it_test = li.begin();
    it_test++;
    it_test++;
    it_test++;
    //std::list<int>::iterator it_test2 = it_test + 1;
   // it_test2++;
    //li.splice(li.begin(), li, it_test2, it_test);
    std::cout << "-------" << std::endl;

    std::list<int> li2;
    li2.push_back(44);
    li2.push_back(5);
    li2.push_back(6);

    li.merge(li2);

    for (std::list<int>::iterator it = li.begin(); it != li.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "================" << std::endl;
    typedef struct s_test {
        int a;
        int b;
    } t_test;

    t_test st;
    st.a = 6;
    st.b = 7;

    t_test st2;
    st2.a = 66;
    st2.b = 77;

    std::list<t_test>lala;
    lala.push_back(st);
    lala.push_back(st2);
    std::list<t_test>::iterator lala_it = lala.begin();
    //std::list<t_test>::iterator lala_2 = lala_it++;




    --lala_it;
    std::cout << (*lala_it).a << std::endl;

    std::cout << "================" << std::endl;


    std::list<int>comp;
    std::list<int>comp2;
    comp.push_back(0);
    comp2.push_back(0);


    std::cout << (comp == comp2) << std::endl;


    comp.push_back(1);
    std::cout << (comp == comp2) << std::endl;

    comp2.push_back(0);
    std::cout << (comp == comp2) << std::endl;
    
    //std::ptrdiff_t ptr = lala_it - lala_2;

    std::cout << "================" << std::endl;

    std::list<std::string> g;
    std::cout << g.front() << std::endl;
    std::cout << g.back() << std::endl;

    std::cout << "================" << std::endl;

    ft::List<int> custom;
    std::cout << custom.size() << std::endl;
    std::cout << custom.front() << std::endl;
    

    std::cout << "================" << std::endl;
    std::cout << "================" << std::endl;
    std::list<int> empty;
    //std::list<int>::iterator t = empty.begin();
    //std::cout << *t << std::endl;

    empty.push_back(10);
    empty.push_back(20);
    empty.push_back(30);
    empty.push_back(40);
    empty.push_back(50);

    std::list<int>::iterator end_test(empty.begin());
    for (; end_test != empty.end(); end_test++)
        std::cout << *end_test << std::endl;

    std::list<int>::iterator end_test2(empty.end());
    std::cout << *end_test2-- << std::endl;
    std::cout << *end_test2 << std::endl;

    ft::List<int>yo;
    yo.push_back(1);
    yo.push_back(12);
    system("leaks a.out");

}