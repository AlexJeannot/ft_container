#include <iostream>
#include <vector>

#include "includes/sequence_containers/Vector.hpp"
#include "test.cpp"

template <typename T>
void testBasics(std::vector<T> vBase, ft::Vector<T> vCustom)
{
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

template <typename T>
void testRelationalOperators(std::vector<T> vBase, std::vector<T> cmp_vBase,
                            ft::Vector<T> vCustom, ft::Vector<T> cmp_vCustom)
{
    ((vBase == cmp_vBase) == (vCustom == cmp_vCustom)) ? fOK("==") : fKO("==");
    ((vBase != cmp_vBase) == (vCustom != cmp_vCustom)) ? fOK("!=") : fKO("!=");
    ((vBase < cmp_vBase) == (vCustom < cmp_vCustom)) ? fOK("<") : fKO("<");
    ((vBase <= cmp_vBase) == (vCustom <= cmp_vCustom)) ? fOK("<=") : fKO("<=");
    ((vBase > cmp_vBase) == (vCustom > cmp_vCustom)) ? fOK(">") : fKO(">");
    ((vBase >= cmp_vBase) == (vCustom >= cmp_vCustom)) ? fOK(">=") : fKO(">=");
}

template <typename T>
void testIterator(std::vector<T> vBase, ft::Vector<T> vCustom)
{
    bool verif = true;
    typename std::vector<T>::iterator itBase;
    typename ft::Vector<T>::iterator itCustom;
    itBase = vBase.begin();
    itCustom = vCustom.begin();

    (*(vBase.begin()) == *(vCustom.begin())) ? fOK("begin()") : fKO("begin()");
    (*(vBase.cbegin()) == *(vCustom.cbegin())) ? fOK("cbegin()") : fKO("cbegin()");
    (*(vBase.end() - 1) == *(vCustom.end() - 1)) ? fOK("end()") : fKO("end()");
    (*(vBase.cend() - 1) == *(vCustom.cend() - 1)) ? fOK("cend()") : fKO("cend()");

    while (itBase != vBase.end())
    {
        if (*itBase++ != *itCustom++)
            verif = false;
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    itBase = --vBase.end();
    itCustom = --vCustom.end();
    while (itBase != vBase.begin())
    {
        if (*itBase-- != *itCustom--)
            verif = false;
    }
    (verif == true) ? fOK("Operator--(int)") : fKO("Operator--(int)");

    verif = true;
    itBase = vBase.begin();
    itCustom = vCustom.begin();
    while (itBase != (vBase.end() - 1))
    {
        if (*++itBase != *++itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    verif = true;
    itBase = vBase.end();
    itCustom = vCustom.end();
    while (itBase != vBase.begin())
    {
        if (*--itBase != *--itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator--()") : fKO("Operator--()");

    itBase = vBase.begin() + 4;
    itCustom = vCustom.begin() + 4;
    (*(itBase) == *(itCustom)) ? fOK("Operator+()") : fKO("Operator+()");

    itBase = vBase.end() - 3;
    itCustom = vCustom.end() - 3;
    (*(itBase) == *(itCustom)) ? fOK("Operator-()") : fKO("Operator-()");

    itBase += 2;
    itCustom += 2;
    (*(itBase) == *(itCustom)) ? fOK("Operator+=()") : fKO("Operator+=()");

    itBase -= 1;
    itCustom -= 1;
    (*(itBase) == *(itCustom)) ? fOK("Operator-=()") : fKO("Operator-=()");

    (itBase[1] == itCustom[1]) ? fOK("Operator[]()") : fKO("Operator[]()");

    ((vBase.begin() == vBase.begin()) == (vCustom.begin() == vCustom.begin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((vBase.begin() != vBase.begin()) == (vCustom.begin() != vCustom.begin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
    ((vBase.begin() < vBase.begin() + 2) == (vCustom.begin() < vCustom.begin() + 2)) ? fOK("Operator<()") : fKO("Operator<()");
    ((vBase.begin() <= vBase.begin()) == (vCustom.begin() <= vCustom.begin())) ? fOK("Operator<=()") : fKO("Operator<=()");
    ((vBase.begin() > vBase.begin() + 2) == (vCustom.begin() > vCustom.begin() + 2)) ? fOK("Operator>()") : fKO("Operator>()");
    ((vBase.begin() >= vBase.begin()) == (vCustom.begin() >= vCustom.begin())) ? fOK("Operator>=()") : fKO("Operator>=()");
}


template <typename T>
void testReverseIterator(std::vector<T> vBase, ft::Vector<T> vCustom)
{
    bool verif = true;
    typename std::vector<T>::reverse_iterator ritBase;
    typename ft::Vector<T>::reverse_iterator ritCustom;
    ritBase = vBase.rbegin();
    ritCustom = vCustom.rbegin();

    (*(vBase.rbegin()) == *(vCustom.rbegin())) ? fOK("rbegin()") : fKO("rbegin()");
    (*(vBase.crbegin()) == *(vCustom.crbegin())) ? fOK("crbegin()") : fKO("crbegin()");
    (*(vBase.rend() - 1) == *(vCustom.rend() - 1)) ? fOK("rend()") : fKO("rend()");
    (*(vBase.crend() - 1) == *(vCustom.crend() - 1)) ? fOK("crend()") : fKO("crend()");

    while (ritBase != vBase.rend())
    {
        if (*ritBase++ != *ritCustom++)
            verif = false;
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    ritBase = vBase.rbegin();
    ritCustom = vCustom.rbegin();
    for (int count = 0; count < 2; count++)
    {
        if (*++ritBase != *++ritCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    ritBase = vBase.rbegin() + 4;
    ritCustom = vCustom.rbegin() + 4;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator+()") : fKO("Operator+()");

    ritBase = vBase.rend() - 3;
    ritCustom = vCustom.rend() - 3;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator-()") : fKO("Operator-()");

    ritBase += 2;
    ritCustom += 2;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator+=()") : fKO("Operator+=()");

    ritBase -= 1;
    ritCustom -= 1;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator-=()") : fKO("Operator-=()");

    (ritBase[1] == ritCustom[1]) ? fOK("Operator[]()") : fKO("Operator[]()");

    ((vBase.rbegin() == vBase.rbegin()) == (vCustom.rbegin() == vCustom.rbegin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((vBase.rbegin() != vBase.rbegin()) == (vCustom.rbegin() != vCustom.rbegin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
    ((vBase.rbegin() < vBase.rbegin() + 2) == (vCustom.rbegin() < vCustom.rbegin() + 2)) ? fOK("Operator<()") : fKO("Operator<()");
    ((vBase.rbegin() <= vBase.rbegin()) == (vCustom.rbegin() <= vCustom.rbegin())) ? fOK("Operator<=()") : fKO("Operator<=()");
    ((vBase.rbegin() > vBase.rbegin() + 2) == (vCustom.rbegin() > vCustom.rbegin() + 2)) ? fOK("Operator>()") : fKO("Operator>()");
    ((vBase.rbegin() >= vBase.rbegin()) == (vCustom.rbegin() >= vCustom.rbegin())) ? fOK("Operator>=()") : fKO("Operator>=()");
}


template <typename T>
void testVector(void)
{
    std::vector<T> vBase;
    ft::Vector<T> vCustom;

    /* Test size() and capacity() at initialization */
    std::cout << "======= TEST 1 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");

    
    /* Test max_size() */
    std::cout << std::endl << "======= TEST 2 =======" << std::endl;
    (vBase.max_size() == vCustom.max_size()) ? fOK("max_size()") : fKO("max_size()");


    /* Test size(), capacity() and front() after adding one element */
    vBase.push_back(33);
    vCustom.push_back(33);
    std::cout << std::endl << "======= TEST 3 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity() and element comparison after superior resize() */
    vBase.resize(10);
    vCustom.resize(10);
    std::cout << std::endl << "======= TEST 4 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity() and front() after clear() */
    vBase.clear();
    vCustom.clear();
    std::cout << std::endl << "======= TEST 5 =======" << std::endl;
    (vBase.size() == vCustom.size()) ? fOK("size()") : fKO("size()");
    (vBase.capacity() == vCustom.capacity()) ? fOK("capacity()") : fKO("capacity()");


    /* Test size(), capacity() and element comparison after inferior resize() */
    for (int count = 0; count < 10; count++)
    {
        vBase.push_back(count);
        vCustom.push_back(count);
    }
    vBase.resize(5);
    vCustom.resize(5);
    std::cout << std::endl << "======= TEST 6 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity() and element comparison after equal resize() */
    vBase.resize(5);
    vCustom.resize(5);
    std::cout << std::endl << "======= TEST 7 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size() and capacity() after reserve() equal to zero */
    vBase.reserve(0);
    vCustom.reserve(0);
    std::cout << std::endl << "======= TEST 8 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size() and capacity() after reserve() inferior than capacity() */
    vBase.reserve(1);
    vCustom.reserve(1);
    std::cout << std::endl << "======= TEST 9 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size() and capacity() after reserve() inferior than 2xsize() */
    vBase.reserve(8);
    vCustom.reserve(8);
    std::cout << std::endl << "======= TEST 10 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size() and capacity() after reserve() superior than 2xsize() */
    vBase.reserve(25);
    vCustom.reserve(25);
    std::cout << std::endl << "======= TEST 11 =======" << std::endl;
    testBasics(vBase, vCustom);


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
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with another vector's iterators */
    std::vector<T> vBase2(vBase);
    vBase.assign(vBase2.begin(), (vBase2.end() - 5));
    vCustom.assign(vBase2.begin(), (vBase2.end() - 5));
    std::cout << std::endl << "======= TEST 17 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with same vector's iterators */
    vBase.assign(vBase.begin() + 2, (vBase.end()));
    vCustom.assign(vCustom.begin() + 2, (vCustom.end()));
    std::cout << std::endl << "======= TEST 18 =======" << std::endl;
    testBasics(vBase, vCustom);

    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with a number of value inferior to capacity() */
    vBase.assign(1, 1);
    vCustom.assign(1, 1);
    std::cout << std::endl << "======= TEST 19 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with a number of value superior to capacity() */
    vBase.assign(1000, 1);
    vCustom.assign(1000, 1);
    std::cout << std::endl << "======= TEST 20 =======" << std::endl;
    testBasics(vBase, vCustom);

    /* Test size(), capacity(), front(), back() and element comparison
    after pop_back() */
    vBase.pop_back();
    vCustom.pop_back();
    std::cout << std::endl << "======= TEST 21 =======" << std::endl;
    testBasics(vBase, vCustom);

    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at begin() */
    vBase.clear();
    vCustom.clear();
    vBase.insert(vBase.begin(), 3);
    vCustom.insert(vCustom.begin(), 3);
    vBase.insert(vBase.begin(), 4);
    vCustom.insert(vCustom.begin(), 4);
    std::cout << std::endl << "======= TEST 22 =======" << std::endl;
    testBasics(vBase, vCustom);

    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at end() */
    vBase.insert(vBase.end(), 5);
    vCustom.insert(vCustom.end(), 5);
    vBase.insert(vBase.end(), 6);
    vCustom.insert(vCustom.end(), 6);
    std::cout << std::endl << "======= TEST 23 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at begin() + 2 */
    vBase.insert(vBase.begin() + 2, 1);
    vCustom.insert(vCustom.begin() + 2, 1);
    vBase.insert(vBase.begin() + 2, 2);
    vCustom.insert(vCustom.begin() + 2, 2);
    std::cout << std::endl << "======= TEST 24 =======" << std::endl;
    testBasics(vBase, vCustom);



    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() */
    vBase.clear();
    vCustom.clear();
    vBase.insert(vBase.begin(), 2, 4);
    vCustom.insert(vCustom.begin(), 2, 4);
    vBase.insert(vBase.begin(), 2, 3);
    vCustom.insert(vCustom.begin(), 2, 3);
    std::cout << std::endl << "======= TEST 25 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() */
    vBase.insert(vBase.begin(), 0, 5);
    vCustom.insert(vCustom.begin(), 0, 5);
    std::cout << std::endl << "======= TEST 26 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at end() */
    vBase.insert(vBase.end(), 10, 5);
    vCustom.insert(vCustom.end(), 10, 5);
    vBase.insert(vBase.end(), 10, 6);
    vCustom.insert(vCustom.end(), 10, 6);
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() + 8 */
    vBase.insert(vBase.begin() + 8, 4, 1);
    vCustom.insert(vCustom.begin() + 8, 4, 1);
    vBase.insert(vBase.begin() + 8, 4, 2);
    vCustom.insert(vCustom.begin() + 8, 4, 2);
    std::cout << std::endl << "======= TEST 28 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from another vector at begin() */
    vBase.clear();
    vCustom.clear();
    vBase.insert(vBase.begin(), vBase2.begin(), vBase2.end());
    vCustom.insert(vCustom.begin(), vBase2.begin(), vBase2.end());
    std::cout << std::endl << "======= TEST 29 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from another vector at begin() + 2 */
    vBase.insert(vBase.begin() + 2, vBase2.begin(), vBase2.end());
    vCustom.insert(vCustom.begin() + 2, vBase2.begin(), vBase2.end());
    std::cout << std::endl << "======= TEST 30 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from same vector at begin() */
    vBase.insert(vBase.begin(), vBase.begin(), vBase.end());
    vCustom.insert(vCustom.begin(), vCustom.begin(), vCustom.end());
    std::cout << std::endl << "======= TEST 31 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from same vector at begin() + 2*/
    vBase.insert(vBase.begin() + 2, vBase.begin(), vBase.end());
    vCustom.insert(vCustom.begin() + 2, vCustom.begin(), vCustom.end());
    std::cout << std::endl << "======= TEST 32 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() 0 elements from same vector at begin() */
    vBase.insert(vBase.begin(), vBase.begin(), vBase.begin());
    vCustom.insert(vCustom.begin(), vCustom.begin(), vCustom.begin());
    std::cout << std::endl << "======= TEST 33 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison after erase() at begin() */
    vBase.erase(vBase.begin());
    vCustom.erase(vCustom.begin());
    std::cout << std::endl << "======= TEST 34 =======" << std::endl;
    testBasics(vBase, vCustom);

    /* Test size(), capacity(), front(), back() and element comparison after erase() at begin() + 2 */
    vBase.erase(vBase.begin() + 2);
    vCustom.erase(vCustom.begin() + 2);
    std::cout << std::endl << "======= TEST 35 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after erase() from begin() to begin() */
    vBase.erase(vBase.begin(), vBase.begin());
    vCustom.erase(vCustom.begin(), vCustom.begin());
    std::cout << std::endl << "======= TEST 36 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after erase() from begin() to end() */
    vBase.erase(vBase.begin(), vBase.end());
    vCustom.erase(vCustom.begin(), vCustom.end());
    std::cout << std::endl << "======= TEST 37 =======" << std::endl;
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


    /* Test relational operators with empty vectors */
    vBase.clear();
    vCustom.clear();
    std::vector<T> cmp_vBase(vBase);
    ft::Vector<T> cmp_vCustom(vCustom);
    std::cout << std::endl << "======= TEST 38 =======" << std::endl;
    testRelationalOperators(vBase, cmp_vBase, vCustom, cmp_vCustom);


    /* Test relational operators with one element in vectors */
    vBase.push_back(1);
    vCustom.push_back(1);
    std::cout << std::endl << "======= TEST 39 =======" << std::endl;
    testRelationalOperators(vBase, cmp_vBase, vCustom, cmp_vCustom);


    /* Test relational operators with same element number and same values in vectors */
    cmp_vBase.push_back(1);
    cmp_vCustom.push_back(1);
    std::cout << std::endl << "======= TEST 40 =======" << std::endl;
    testRelationalOperators(vBase, cmp_vBase, vCustom, cmp_vCustom);


    /* Test relational operators with same element number but different values in vectors */
    cmp_vBase.push_back(1);
    cmp_vCustom.push_back(1);
    vBase.push_back(2);
    vCustom.push_back(2);
    std::cout << std::endl << "======= TEST 41 =======" << std::endl;
    testRelationalOperators(vBase, cmp_vBase, vCustom, cmp_vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after swap() of same size vectors */
    vBase.swap(cmp_vBase);
    vCustom.swap(cmp_vCustom);
    std::cout << std::endl << "======= TEST 42 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after swap() of different size vectors (inferior size) */
    cmp_vBase.push_back(3);
    cmp_vCustom.push_back(3);
    vBase.swap(cmp_vBase);
    vCustom.swap(cmp_vCustom);
    std::cout << std::endl << "======= TEST 43 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after swap() of different size vectors (superior size) */
    vBase.insert(vBase.end(), 3, 4);
    vCustom.insert(vCustom.end(), 3, 4);
    vBase.swap(cmp_vBase);
    vCustom.swap(cmp_vCustom);
    std::cout << std::endl << "======= TEST 44 =======" << std::endl;
    testBasics(vBase, vCustom);


    /* Test normal iterators */
    vBase.clear();
    vCustom.clear();
    for (int count = 0; count < 10; count++)
    {
        vBase.push_back(count);
        vCustom.push_back(count);
    }
    std::cout << std::endl << "======= TEST 45 =======" << std::endl;
    testIterator(vBase, vCustom);


   /* Test reverse iterators */

    std::cout << std::endl << "======= TEST 46 =======" << std::endl;
    testReverseIterator(vBase, vCustom);

}

int main()
{
    std::cout << "\033[38;5;202m******************************************************" << std::endl;
    std::cout << "***************       TEST VECTOR       **************" << std::endl;
    std::cout << "******************************************************\033[0m" << std::endl;

    std::cout << std::endl;
    std::cout << "\033[38;5;51m>>>>>>>>>>>>>>>      vector<char>      <<<<<<<<<<<<<<<\033[0m" << std::endl << std::endl;
    testVector<char>();

    std::cout << std::endl << std::endl;
    std::cout << "\033[38;5;51m>>>>>>>>>>>>>>>       vector<int>      <<<<<<<<<<<<<<<\033[0m" << std::endl << std::endl;
    testVector<int>();

    return (0);
}