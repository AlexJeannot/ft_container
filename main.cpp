#include <iostream>
#include <vector>

#include "includes/sequence_containers/Vector.hpp"
#define OK "\033[38;5;40mOK\033[0m"
#define KO "\033[38;5;124mKO\033[0m"

//    std::cout << vBase.size() << std::endl;
//    std::cout << vCustom.size() << std::endl;

void fOK(std::string test)
{
    std::cout << OK << "\033[38;5;43m >> " << test << "\033[0m" << std::endl;
}

void fKO(std::string test)
{
    std::cout << KO << "\033[38;5;43m >> " << test << "\033[0m" << std::endl;
}

void testVector(void)
{
    std::vector<int> vBase;
    ft::Vector<int> vCustom;

    /* Test size() and capacity() at initialization */
    std::cout << "======= TEST 1 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");

    
    /* Test max_size() */
    std::cout << std::endl << "======= TEST 2 =======" << std::endl;
    (vBase.max_size() == vCustom.max_size()) ? fOK("max_size()") : fKO("max_size()");


    /* Test size(), capacity() and front() after adding one element */
    vBase.push_back(0);
    vCustom.push_back(0);
    std::cout << std::endl << "======= TEST 3 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");


    /* Test size(), capacity() and element comparison after superior resize() */
    vBase.resize(10);
    vCustom.resize(10);
    std::cout << std::endl << "======= TEST 4 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity() and front() after clear() */
    vBase.clear();
    vCustom.clear();
    std::cout << std::endl << "======= TEST 5 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");


    /* Test size(), capacity() and element comparison after inferior resize() */
    for (int count = 0; count < 10; count++)
    {
        vBase.push_back(count);
        vCustom.push_back(count);
    }
    vBase.resize(5);
    vCustom.resize(5);
    std::cout << std::endl << "======= TEST 6 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity() and element comparison after equal resize() */
    vBase.resize(5);
    vCustom.resize(5);
    std::cout << std::endl << "======= TEST 7 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size() and capacity() after reserve() equal to zero */
    vBase.reserve(0);
    vCustom.reserve(0);
    std::cout << std::endl << "======= TEST 8 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");


    /* Test size() and capacity() after reserve() inferior than capacity() */
    vBase.reserve(1);
    vCustom.reserve(1);
    std::cout << std::endl << "======= TEST 9 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");


    /* Test size() and capacity() after reserve() inferior than 2xsize() */
    vBase.reserve(8);
    vCustom.reserve(8);
    std::cout << std::endl << "======= TEST 10 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");


    /* Test size() and capacity() after reserve() superior than 2xsize() */
    vBase.reserve(25);
    vCustom.reserve(25);
    std::cout << std::endl << "======= TEST 11 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");


    /* Test empty() before clear() */
    std::cout << std::endl << "======= TEST 12 =======" << std::endl;
    (vBase.empty() == vCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty() after clear() */
    vBase.clear();
    vCustom.clear();
    std::cout << std::endl << "======= TEST 13 =======" << std::endl;
    (vBase.empty() == vCustom.empty()) ? fOK("empty()") : fKO("empty()");



    /* Test at() in bounds */
    for (int count = 0; count < 10; count++)
    {
        vBase.push_back(count);
        vCustom.push_back(count);
    }
    std::cout << std::endl << "======= TEST 14 =======" << std::endl;
    (vBase.at(2) == vCustom.at(2)) ? fOK("at()") : fKO("at()");


    /* Test at() out of bounds */
    std::cout << std::endl << "======= TEST 15 =======" << std::endl;
    std::cout << "\033[38;5;43mstd::vector exception: \033[0m";
    try
    {
        vBase.at(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\033[38;5;43mft::vector exception: \033[0m";
    try
    {
        vCustom.at(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    /* Test front() and back() */
    std::cout << std::endl << "======= TEST 16 =======" << std::endl;
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");


    /* Test size(), capacity(), front(), back() and element comparison after assign() with another vector's iterators */
    std::vector<int> vBase2(vBase);
    vBase.assign(vBase2.begin(), (vBase2.end() - 5));
    vCustom.assign(vBase2.begin(), (vBase2.end() - 5));
    std::cout << std::endl << "======= TEST 17 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity(), front(), back() and element comparison after assign() with same vector's iterators */
    vBase.assign(vBase.begin() + 2, (vBase.end()));
    vCustom.assign(vCustom.begin() + 2, (vCustom.end()));
    std::cout << std::endl << "======= TEST 18 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }

    /* Test size(), capacity(), front(), back() and element comparison after assign() 
    with a number of value inferior to capacity() */
    vBase.assign(1, 1);
    vCustom.assign(1, 1);
    std::cout << std::endl << "======= TEST 19 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity(), front(), back() and element comparison after assign() 
    with a number of value superior to capacity() */
    vBase.assign(1000, 1);
    vCustom.assign(1000, 1);
    std::cout << std::endl << "======= TEST 20 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }

    /* Test size(), capacity(), front(), back() and element comparison after pop_back() */
    vBase.pop_back();
    vCustom.pop_back();
    std::cout << std::endl << "======= TEST 21 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }

    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at begin() */
    vBase.clear();
    vCustom.clear();
    vBase.insert(vBase.begin(), 3);
    vCustom.insert(vCustom.begin(), 3);
    vBase.insert(vBase.begin(), 4);
    vCustom.insert(vCustom.begin(), 4);
    std::cout << std::endl << "======= TEST 22 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }

    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at end() */
    vBase.insert(vBase.end(), 5);
    vCustom.insert(vCustom.end(), 5);
    vBase.insert(vBase.end(), 6);
    vCustom.insert(vCustom.end(), 6);
    std::cout << std::endl << "======= TEST 23 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at begin() + 2 */
    vBase.insert(vBase.begin() + 2, 1);
    vCustom.insert(vCustom.begin() + 2, 1);
    vBase.insert(vBase.begin() + 2, 2);
    vCustom.insert(vCustom.begin() + 2, 2);
    std::cout << std::endl << "======= TEST 24 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() */
    vBase.clear();
    vCustom.clear();
    vBase.insert(vBase.begin(), 2, 4);
    vCustom.insert(vCustom.begin(), 2, 4);
    vBase.insert(vBase.begin(), 2, 3);
    vCustom.insert(vCustom.begin(), 2, 3);
    std::cout << std::endl << "======= TEST 25 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at end() */
    vBase.insert(vBase.end(), 10, 5);
    vCustom.insert(vCustom.end(), 10, 5);
    vBase.insert(vBase.end(), 10, 6);
    vCustom.insert(vCustom.end(), 10, 6);
    std::cout << std::endl << "======= TEST 26 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() + 8 */
    vBase.insert(vBase.begin() + 8, 4, 1);
    vCustom.insert(vCustom.begin() + 8, 4, 1);
    vBase.insert(vBase.begin() + 8, 4, 2);
    vCustom.insert(vCustom.begin() + 8, 4, 2);
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }



    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from another vector at begin() */
    vBase.clear();
    vCustom.clear();
    vBase.insert(vBase.begin(), vBase2.begin(), vBase2.end());
    vCustom.insert(vCustom.begin(), vBase2.begin(), vBase2.end());
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }

    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from another vector at begin() + 2 */
    vBase.insert(vBase.begin() + 2, vBase2.begin(), vBase2.end());
    vCustom.insert(vCustom.begin() + 2, vBase2.begin(), vBase2.end());
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }

    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from same vector at begin() */
    vBase.insert(vBase.begin(), vBase.begin(), vBase.end());
    vCustom.insert(vCustom.begin(), vCustom.begin(), vCustom.end());
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }

    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from same vector at begin() + 2*/
    vBase.insert(vBase.begin() + 2, vBase.begin(), vBase.end());
    vCustom.insert(vCustom.begin() + 2, vCustom.begin(), vCustom.end());
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");
    (vBase.front() == vCustom.front()) ? fOK("front()") : fKO("front()");
    (vBase.back() == vCustom.back()) ? fOK("back()") : fKO("back()");
    for (int count = 0; count < vBase.size(); count++)
    {
        if (vBase[count] != vCustom[count])
        {
            fKO("vector's elements");
            break;
        }
    }











}

int main()
{
    testVector();
    return (0);
}

/*
int main()
{

    std::vector<int> a;
    std::vector<int> b(2, 1);
    std::vector<int> c(3);

    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << "b.size() = " << b.size() << std::endl;
    std::cout << "c.size() = " << c.size() << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "a.capacity() = " << a.capacity() << std::endl;
    std::cout << "b.capacity() = " << b.capacity() << std::endl;
    std::cout << "c.capacity() = " << c.capacity() << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "a.max_size() = " << a.max_size() << std::endl;
    std::cout << "b.max_size() = " << b.max_size() << std::endl;
    std::cout << "c.max_size() = " << c.max_size() << std::endl;
    int s = a.size();

    std::cout << "---------" << std::endl;
    for (auto iter = a.begin(); iter != a.end(); iter++)
        std::cout << *iter << std::endl;

    std::cout << "---------" << std::endl;
    for (auto iter = b.begin(); iter != b.end(); iter++)
        std::cout << *iter << std::endl;

    std::cout << "---------" << std::endl;
    for (auto iter = c.begin(); iter != c.end(); iter++)
        std::cout << *iter << std::endl;

    std::cout << "---------" << std::endl << "---------" << std::endl;
    test<int> d;
    d.f1();

    std::cout << "---------" << std::endl;

    test<std::string> e;
    e.f1();

    std::cout << "---------" << std::endl;

    test<char> f;
    f.f1();

    std::cout << "---------" << std::endl;

    test<float> g;
    g.f1();


    //ft::Vector<int> v;
    //ft::Vector<int> v1(2);
    //ft::Vector<int> v2(2, 2);
    //ft::Vector<int> v3(v2);

   // std::cout << "v1.size() = " << v1.size() << std::endl;
    //std::cout << "v1.max_size() = " << v1.max_size() << std::endl;

    //ft::Vector<char> v4;
    std::vector<char> cc;


    //std::cout << "v4.size() = " << v4.size() << std::endl;
    //std::cout << "v4.max_size() = " << v4.max_size() << std::endl;
    //std::cout << "cc.max_size() = " << cc.max_size() << std::endl;

    std::cout << "---------" << std::endl;

    std::cout << "int() = " << int() << std::endl;
    std::cout << "std::string() = " << std::string() << std::endl;
    std::vector<double> cc2;
    std::cout << "cc2.max_size() = " << cc2.max_size() << std::endl;
    //ft::Vector<double> v5;
    //std::cout << "v5.max_size() = " << v5.max_size() << std::endl;

    std::cout << "---------" << std::endl;

    std::vector<double> cc3;
    //ft::Vector<char*> v6;

    std::cout << "cc3.max_size() = " << cc3.max_size() << std::endl;
    //std::cout << "v6.max_size() = " << v6.max_size() << std::endl;

    std::cout << "---------" << std::endl;

    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << "a.capacity() = " << a.capacity() << std::endl;

    for (int count = 0; count < 10; count++)
    {
        std::cout << "=========" << std::endl;
        a.insert(a.end(), 1);
        std::cout << "a.size() = " << a.size() << std::endl;
        std::cout << "a.capacity() = " << a.capacity() << std::endl;
    }

    std::cout << ">>" << std::endl;
    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << "a.capacity() = " << a.capacity() << std::endl;
    std::cout << ">>" << std::endl;
    a.reserve(10);
    std::cout << "a.capacity() = " << a.capacity() << std::endl;
    std::cout << ">>" << std::endl;
    a.insert(a.end(), 1);
    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << "a.capacity() = " << a.capacity() << std::endl;
    std::cout << ">>" << std::endl;
    a.insert(a.end(), 10, 1);
    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << "a.capacity() = " << a.capacity() << std::endl;
    std::cout << ">>" << std::endl;
    a.insert(a.end(), 9, 1);
    std::cout << "a.size() = " << a.size() << std::endl;
    std::cout << "a.capacity() = " << a.capacity() << std::endl;


    std::cout << "===============================================================" << std::endl;

    std::vector<char> charr;

    for (int count = 0; count < 10; count++)
    {
        std::cout << "=========" << std::endl;
        charr.insert(charr.end(), 1);
        std::cout << "charr.size() = " << charr.size() << std::endl;
        std::cout << "charr.capacity() = " << charr.capacity() << std::endl;
    }

    std::cout << "===============================================================" << std::endl;

    std::vector<char>::iterator iter1(charr.begin());

    char *ptr = &charr[1];

    //std::vector<char>::iterator iter2(ptr);

    struct osef {
        int a;
        int b;
    };

    std::vector<osef> myvector;
    osef ss;
    ss.a = 4;
    ss.b = 5;

    osef ss2;
    ss2.a = 77;
    ss2.b = 88;


    myvector.push_back(ss);
    myvector.push_back(ss2);
    std::vector<osef>::iterator iter2 = myvector.begin();
    std::cout << iter2->a << std::endl;
    std::cout << iter2->b << std::endl;
    iter2++;
    std::cout << iter2->a << std::endl;
    std::cout << iter2->b << std::endl;
    std::cout << "======================" << std::endl;
    iter2 = myvector.begin();

    std::cout << iter2[0].a << std::endl;
    std::cout << iter2[1].a << std::endl;

    iter2++;
    std::cout << iter2[0].a << std::endl;
    iter2 -= 1;
    std::cout << iter2[0].a << std::endl;
    iter2 += 1;
    std::cout << iter2[0].a << std::endl;

    std::cout << "======================" << std::endl;
    std::vector<int> rev;
    rev.push_back(1);
    rev.push_back(2);
    rev.push_back(3);

    std::vector<int>::iterator it = rev.begin();
    std::vector<int>::reverse_iterator rit = rev.rbegin();
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*rit = " << *rit << std::endl;
    it += 1;
    rit += 1;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*rit = " << *rit << std::endl;
    std::vector<int>::iterator in = rev.end();
    in--;
    std::cout << "return isnert = " << *(rev.insert(in, 7)) << std::endl;
    for (auto x : rev)
        std::cout << x << std::endl;

    rev.reserve(20);
    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;
    std::cout << "======================" << std::endl;
    rev.clear();

    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;

    std::cout << "======================" << std::endl;
    rev.push_back(1);
    rev.push_back(2);
    rev.push_back(3);
    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;

    std::cout << "======================" << std::endl;
    rev.assign(6, 1);
    for (auto x : rev)
        std::cout << x << std::endl;
    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;
    rev.push_back(3);
    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;

    std::cout << "======================" << std::endl;

    rev.push_back(33);
    rev.push_back(44);
    rev.push_back(55);
    rev.push_back(66);
    rev.push_back(77);
    for (auto x : rev)
        std::cout << x << std::endl;

    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;
    rev.assign(rev.begin(), rev.begin() + 2);

    std::cout << "===========" << std::endl;
    for (auto x : rev)
        std::cout << x << std::endl;

    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;

    std::vector<int> rev2(30, 1);
    rev2.push_back(8);
    rev2.push_back(9);
    rev2.push_back(10);

    std::cout << "===========" << std::endl;
    rev.assign(rev2.begin(), rev2.end());
    for (auto x : rev)
        std::cout << x << std::endl;

    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;

    rev.pop_back();


    std::cout << "rev.size() = " << rev.size() << std::endl;
    std::cout << "rev.capacity() = " << rev.capacity() << std::endl;
    for (auto x : rev)
        std::cout << x << std::endl;
    std::cout << "===========" << std::endl;
    rev.clear();
    rev.push_back(1);
    rev.push_back(2);
    rev.push_back(3);
    rev.push_back(4);
    std::vector<int>::iterator it_test_rev = rev.begin();
    for (auto x : rev)
        std::cout << x << std::endl;
    it_test_rev++;
    std::vector<int>::reverse_iterator rit_test_rev(it_test_rev);
   // std::vector<int>::iterator it_test_rev2(rit_test_rev);

    std::cout << "*it_test_rev = " << *it_test_rev << std::endl;
    std::cout << "*rit_test_rev = " << *rit_test_rev << std::endl;
    //std::cout << "*it_test_rev2 = " << *it_test_rev2 << std::endl;

    //std::vector<int>rev;
    //try
    //{
    ///    std::cout << rev.max_size() << std::endl;
    //    rev.reserve(4611686018427387904);
    //}
    //catch(const std::exception& e)
    //{
    //    std::cerr << e.what() << '\n';
    //}

    try
    {
        std::cout << rev.at(0) << std::endl;
    }
    catch ( std::exception &e)
    {
        std::cerr <<"exception: >" << e.what() << '\n';
    }
    
    return (0);
}
*/