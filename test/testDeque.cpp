#include <deque>
#include "../includes/sequence_containers/Deque.hpp"
#include "test.hpp"

template <typename T>
void testBasics(std::deque<T> dBase, ft::Deque<T> dCustom)
{
    (dBase.size() == dCustom.size()) ? fOK("size()") : fKO("size()");
    (dBase.front() == dCustom.front()) ? fOK("front()") : fKO("front()");
    (dBase.back() == dCustom.back()) ? fOK("back()") : fKO("back()");
    for (size_t count = 0; count < dBase.size(); count++)
    {
        if (dBase[count] != dCustom[count])
        {
            fKO("deque's elements");
            break;
        }
    }
}

template <typename T>
void testRelationalOperators(std::deque<T> dBase, std::deque<T> cmp_dBase,
                            ft::Deque<T> dCustom, ft::Deque<T> cmp_dCustom)
{
    ((dBase == cmp_dBase) == (dCustom == cmp_dCustom)) ? fOK("==") : fKO("==");
    ((dBase != cmp_dBase) == (dCustom != cmp_dCustom)) ? fOK("!=") : fKO("!=");
    ((dBase < cmp_dBase) == (dCustom < cmp_dCustom)) ? fOK("<") : fKO("<");
    ((dBase <= cmp_dBase) == (dCustom <= cmp_dCustom)) ? fOK("<=") : fKO("<=");
    ((dBase > cmp_dBase) == (dCustom > cmp_dCustom)) ? fOK(">") : fKO(">");
    ((dBase >= cmp_dBase) == (dCustom >= cmp_dCustom)) ? fOK(">=") : fKO(">=");
}

template <typename T>
void testIterator(std::deque<T> dBase, ft::Deque<T> dCustom)
{
    bool verif = true;
    typename std::deque<T>::iterator itBase;
    typename ft::Deque<T>::iterator itCustom;
    itBase = dBase.begin();
    itCustom = dCustom.begin();

    (*(dBase.begin()) == *(dCustom.begin())) ? fOK("begin()") : fKO("begin()");
    (*(dBase.cbegin()) == *(dCustom.cbegin())) ? fOK("cbegin()") : fKO("cbegin()");
    (*(dBase.end() - 1) == *(dCustom.end() - 1)) ? fOK("end()") : fKO("end()");
    (*(dBase.cend() - 1) == *(dCustom.cend() - 1)) ? fOK("cend()") : fKO("cend()");

    while (itBase != dBase.end())
    {
        if (*itBase++ != *itCustom++)
            verif = false;
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    itBase = --dBase.end();
    itCustom = --dCustom.end();
    while (itBase != dBase.begin())
    {
        if (*itBase-- != *itCustom--)
            verif = false;
    }
    (verif == true) ? fOK("Operator--(int)") : fKO("Operator--(int)");

    verif = true;
    itBase = dBase.begin();
    itCustom = dCustom.begin();
    while (itBase != (dBase.end() - 1))
    {
        if (*++itBase != *++itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    verif = true;
    itBase = dBase.end();
    itCustom = dCustom.end();
    while (itBase != dBase.begin())
    {
        if (*--itBase != *--itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator--()") : fKO("Operator--()");

    itBase = dBase.begin() + 4;
    itCustom = dCustom.begin() + 4;
    (*(itBase) == *(itCustom)) ? fOK("Operator+()") : fKO("Operator+()");

    itBase = dBase.end() - 3;
    itCustom = dCustom.end() - 3;
    (*(itBase) == *(itCustom)) ? fOK("Operator-()") : fKO("Operator-()");

    itBase += 2;
    itCustom += 2;
    (*(itBase) == *(itCustom)) ? fOK("Operator+=()") : fKO("Operator+=()");

    itBase -= 1;
    itCustom -= 1;
    (*(itBase) == *(itCustom)) ? fOK("Operator-=()") : fKO("Operator-=()");

    (itBase[1] == itCustom[1]) ? fOK("Operator[]()") : fKO("Operator[]()");

    ((dBase.begin() == dBase.begin()) == (dCustom.begin() == dCustom.begin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((dBase.begin() != dBase.begin()) == (dCustom.begin() != dCustom.begin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
    ((dBase.begin() < dBase.begin() + 2) == (dCustom.begin() < dCustom.begin() + 2)) ? fOK("Operator<()") : fKO("Operator<()");
    ((dBase.begin() <= dBase.begin()) == (dCustom.begin() <= dCustom.begin())) ? fOK("Operator<=()") : fKO("Operator<=()");
    ((dBase.begin() > dBase.begin() + 2) == (dCustom.begin() > dCustom.begin() + 2)) ? fOK("Operator>()") : fKO("Operator>()");
    ((dBase.begin() >= dBase.begin()) == (dCustom.begin() >= dCustom.begin())) ? fOK("Operator>=()") : fKO("Operator>=()");
}


template <typename T>
void testReverseIterator(std::deque<T> dBase, ft::Deque<T> dCustom)
{
    bool verif = true;
    typename std::deque<T>::reverse_iterator ritBase;
    typename ft::Deque<T>::reverse_iterator ritCustom;
    ritBase = dBase.rbegin();
    ritCustom = dCustom.rbegin();

    (*(dBase.rbegin()) == *(dCustom.rbegin())) ? fOK("rbegin()") : fKO("rbegin()");
    (*(dBase.crbegin()) == *(dCustom.crbegin())) ? fOK("crbegin()") : fKO("crbegin()");
    (*(dBase.rend() - 1) == *(dCustom.rend() - 1)) ? fOK("rend()") : fKO("rend()");
    (*(dBase.crend() - 1) == *(dCustom.crend() - 1)) ? fOK("crend()") : fKO("crend()");

    while (ritBase != dBase.rend())
    {
        if (*ritBase++ != *ritCustom++)
            verif = false;
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    ritBase = dBase.rbegin();
    ritCustom = dCustom.rbegin();
    for (int count = 0; count < 2; count++)
    {
        if (*++ritBase != *++ritCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    ritBase = dBase.rbegin() + 4;
    ritCustom = dCustom.rbegin() + 4;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator+()") : fKO("Operator+()");

    ritBase = dBase.rend() - 3;
    ritCustom = dCustom.rend() - 3;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator-()") : fKO("Operator-()");

    ritBase += 2;
    ritCustom += 2;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator+=()") : fKO("Operator+=()");

    ritBase -= 1;
    ritCustom -= 1;
    (*(ritBase) == *(ritCustom)) ? fOK("Operator-=()") : fKO("Operator-=()");

    (ritBase[1] == ritCustom[1]) ? fOK("Operator[]()") : fKO("Operator[]()");

    ((dBase.rbegin() == dBase.rbegin()) == (dCustom.rbegin() == dCustom.rbegin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((dBase.rbegin() != dBase.rbegin()) == (dCustom.rbegin() != dCustom.rbegin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
    ((dBase.rbegin() < dBase.rbegin() + 2) == (dCustom.rbegin() < dCustom.rbegin() + 2)) ? fOK("Operator<()") : fKO("Operator<()");
    ((dBase.rbegin() <= dBase.rbegin()) == (dCustom.rbegin() <= dCustom.rbegin())) ? fOK("Operator<=()") : fKO("Operator<=()");
    ((dBase.rbegin() > dBase.rbegin() + 2) == (dCustom.rbegin() > dCustom.rbegin() + 2)) ? fOK("Operator>()") : fKO("Operator>()");
    ((dBase.rbegin() >= dBase.rbegin()) == (dCustom.rbegin() >= dCustom.rbegin())) ? fOK("Operator>=()") : fKO("Operator>=()");
}


template <typename T>
void testDeque(void)
{
    std::deque<T> dBase;
    ft::Deque<T> dCustom;

    /* Test size() at initialization */
    std::cout << std::endl << "======= TEST 1 =======" << std::endl;
    (dBase.size() == dCustom.size()) ? fOK("size()") : fKO("size()");

    
    /* Test max_size() */
    std::cout << std::endl << "======= TEST 2 =======" << std::endl;
    (dBase.max_size() == dCustom.max_size()) ? fOK("max_size()") : fKO("max_size()");


    /* Test size() and front() after adding one element */
    dBase.push_back(33);
    dCustom.push_back(33);
    std::cout << std::endl << "======= TEST 3 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size() and element comparison after superior resize() */
    dBase.resize(10);
    dCustom.resize(10);
    std::cout << std::endl << "======= TEST 4 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size() and front() after clear() */
    dBase.clear();
    dCustom.clear();
    std::cout << std::endl << "======= TEST 5 =======" << std::endl;
    (dBase.size() == dCustom.size()) ? fOK("size()") : fKO("size()");


    /* Test size() and element comparison after inferior resize() */
    for (int count = 0; count < 10; count++)
    {
        dBase.push_back(count);
        dCustom.push_back(count);
    }
    dBase.resize(5);
    dCustom.resize(5);
    std::cout << std::endl << "======= TEST 6 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size() and element comparison after equal resize() */
    dBase.resize(5);
    dCustom.resize(5);
    std::cout << std::endl << "======= TEST 7 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test empty() before clear() */
    std::cout << std::endl << "======= TEST 8 =======" << std::endl;
    (dBase.empty() == dCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty() after clear() */
    dBase.clear();
    dCustom.clear();
    std::cout << std::endl << "======= TEST 9 =======" << std::endl;
    (dBase.empty() == dCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test at() in bounds */
    for (int count = 0; count < 10; count++)
    {
        dBase.push_back(count);
        dCustom.push_back(count);
    }
    std::cout << std::endl << "======= TEST 10 =======" << std::endl;
    (dBase.at(2) == dCustom.at(2)) ? fOK("at()") : fKO("at()");


    /* Test at() out of bounds */
    std::cout << std::endl << "======= TEST 11 =======" << std::endl;
    std::cout << "\033[38;5;43mstd::deque exception: \033[0m";
    try
    {
        dBase.at(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\033[38;5;43mft::deque exception: \033[0m";
    try
    {
        dCustom.at(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    /* Test front() and back() */
    std::cout << std::endl << "======= TEST 12 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after assign() with another deque's iterators */
    std::deque<T> dBase2(dBase);
    dBase.assign(dBase2.begin(), (dBase2.end() - 5));
    dCustom.assign(dBase2.begin(), (dBase2.end() - 5));
    std::cout << std::endl << "======= TEST 13 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after assign() with same deque's iterators */
    dBase.assign(dBase.begin() + 2, (dBase.end()));
    dCustom.assign(dCustom.begin() + 2, (dCustom.end()));
    std::cout << std::endl << "======= TEST 14 =======" << std::endl;
    testBasics(dBase, dCustom);

    /* Test size(), front(), back() and element comparison
    after assign() with a small value */
    dBase.assign(1, 1);
    dCustom.assign(1, 1);
    std::cout << std::endl << "======= TEST 15 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after assign() with a large value */
    dBase.assign(1000, 1);
    dCustom.assign(1000, 1);
    std::cout << std::endl << "======= TEST 16 =======" << std::endl;
    testBasics(dBase, dCustom);

    /* Test size(), front(), back() and element comparison
    after pop_back() */
    dBase.pop_back();
    dCustom.pop_back();
    std::cout << std::endl << "======= TEST 17 =======" << std::endl;
    testBasics(dBase, dCustom);

    /* Test size(), front(), back() and element comparison
    after insert() at begin() */
    dBase.clear();
    dCustom.clear();
    dBase.insert(dBase.begin(), 3);
    dCustom.insert(dCustom.begin(), 3);
    dBase.insert(dBase.begin(), 4);
    dCustom.insert(dCustom.begin(), 4);
    std::cout << std::endl << "======= TEST 18 =======" << std::endl;
    testBasics(dBase, dCustom);

    /* Test size(), front(), back() and element comparison
    after insert() at end() */
    dBase.insert(dBase.end(), 5);
    dCustom.insert(dCustom.end(), 5);
    dBase.insert(dBase.end(), 6);
    dCustom.insert(dCustom.end(), 6);
    std::cout << std::endl << "======= TEST 19 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() at begin() + 2 */
    dBase.insert(dBase.begin() + 2, 1);
    dCustom.insert(dCustom.begin() + 2, 1);
    dBase.insert(dBase.begin() + 2, 2);
    dCustom.insert(dCustom.begin() + 2, 2);
    std::cout << std::endl << "======= TEST 20 =======" << std::endl;
    testBasics(dBase, dCustom);



    /* Test size(), front(), back() and element comparison
    after insert() n elements at begin() */
    dBase.clear();
    dCustom.clear();
    dBase.insert(dBase.begin(), 2, 4);
    dCustom.insert(dCustom.begin(), 2, 4);
    dBase.insert(dBase.begin(), 2, 3);
    dCustom.insert(dCustom.begin(), 2, 3);
    std::cout << std::endl << "======= TEST 21 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() n elements at begin() */
    dBase.insert(dBase.begin(), 0, 5);
    dCustom.insert(dCustom.begin(), 0, 5);
    std::cout << std::endl << "======= TEST 22 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() n elements at end() */
    dBase.insert(dBase.end(), 10, 5);
    dCustom.insert(dCustom.end(), 10, 5);
    dBase.insert(dBase.end(), 10, 6);
    dCustom.insert(dCustom.end(), 10, 6);
    std::cout << std::endl << "======= TEST 23 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() n elements at begin() + 8 */
    dBase.insert(dBase.begin() + 8, 4, 1);
    dCustom.insert(dCustom.begin() + 8, 4, 1);
    dBase.insert(dBase.begin() + 8, 4, 2);
    dCustom.insert(dCustom.begin() + 8, 4, 2);
    std::cout << std::endl << "======= TEST 24 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() n elements from another deque at begin() */
    dBase.clear();
    dCustom.clear();
    dBase.insert(dBase.begin(), dBase2.begin(), dBase2.end());
    dCustom.insert(dCustom.begin(), dBase2.begin(), dBase2.end());
    std::cout << std::endl << "======= TEST 25 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() n elements from another deque at begin() + 2 */
    dBase.insert(dBase.begin() + 2, dBase2.begin(), dBase2.end());
    dCustom.insert(dCustom.begin() + 2, dBase2.begin(), dBase2.end());
    std::cout << std::endl << "======= TEST 26 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() n elements from same deque at begin() */
    dBase.insert(dBase.begin(), dBase.begin(), dBase.end());
    dCustom.insert(dCustom.begin(), dCustom.begin(), dCustom.end());
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() n elements from same deque at begin() + 2*/
    dBase.insert(dBase.begin() + 2, dBase.begin(), dBase.end());
    dCustom.insert(dCustom.begin() + 2, dCustom.begin(), dCustom.end());
    std::cout << std::endl << "======= TEST 28 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after insert() 0 elements from same deque at begin() */
    dBase.insert(dBase.begin(), dBase.begin(), dBase.begin());
    dCustom.insert(dCustom.begin(), dCustom.begin(), dCustom.begin());
    std::cout << std::endl << "======= TEST 29 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison after erase() at begin() */
    dBase.erase(dBase.begin());
    dCustom.erase(dCustom.begin());
    std::cout << std::endl << "======= TEST 30 =======" << std::endl;
    testBasics(dBase, dCustom);

    /* Test size(), front(), back() and element comparison after erase() at begin() + 2 */
    dBase.erase(dBase.begin() + 2);
    dCustom.erase(dCustom.begin() + 2);
    std::cout << std::endl << "======= TEST 31 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after erase() from begin() to begin() */
    dBase.erase(dBase.begin(), dBase.begin());
    dCustom.erase(dCustom.begin(), dCustom.begin());
    std::cout << std::endl << "======= TEST 32 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after erase() from begin() to end() */
    dBase.erase(dBase.begin(), dBase.end());
    dCustom.erase(dCustom.begin(), dCustom.end());
    std::cout << std::endl << "======= TEST 33 =======" << std::endl;
    (dBase.size() == dCustom.size()) ? fOK("size()") : fKO("size()");
    for (size_t count = 0; count < dBase.size(); count++)
    {

        if (dBase[count] != dCustom[count])
        {
            fKO("deque's elements");
            break;
        }
    }

    /* Test size(), front(), back() and element comparison
    after push_front() with empty deque */
    dBase.push_front(34);
    dCustom.push_front(34);
    std::cout << std::endl << "======= TEST 34 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after push_front() with not empty deque */
    dBase.push_front(34);
    dCustom.push_front(34);
    std::cout << std::endl << "======= TEST 35 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after push_front() */
    dBase.pop_front();
    dCustom.pop_front();
    std::cout << std::endl << "======= TEST 36 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test relational operators with empty deques */
    dBase.clear();
    dCustom.clear();
    std::deque<T> cmp_dBase(dBase);
    ft::Deque<T> cmp_dCustom(dCustom);
    std::cout << std::endl << "======= TEST 37 =======" << std::endl;
    testRelationalOperators(dBase, cmp_dBase, dCustom, cmp_dCustom);


    /* Test relational operators with one element in deques */
    dBase.push_back(1);
    dCustom.push_back(1);
    std::cout << std::endl << "======= TEST 38 =======" << std::endl;
    testRelationalOperators(dBase, cmp_dBase, dCustom, cmp_dCustom);


    /* Test relational operators with same element number and same values in deques */
    cmp_dBase.push_back(1);
    cmp_dCustom.push_back(1);
    std::cout << std::endl << "======= TEST 39 =======" << std::endl;
    testRelationalOperators(dBase, cmp_dBase, dCustom, cmp_dCustom);


    /* Test relational operators with same element number but different values in deques */
    cmp_dBase.push_back(1);
    cmp_dCustom.push_back(1);
    dBase.push_back(2);
    dCustom.push_back(2);
    std::cout << std::endl << "======= TEST 40 =======" << std::endl;
    testRelationalOperators(dBase, cmp_dBase, dCustom, cmp_dCustom);


    /* Test size(), front(), back() and element comparison
    after swap() of same size deques */
    dBase.swap(cmp_dBase);
    dCustom.swap(cmp_dCustom);
    std::cout << std::endl << "======= TEST 41 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after swap() of different size deques (inferior size) */
    cmp_dBase.push_back(3);
    cmp_dCustom.push_back(3);
    dBase.swap(cmp_dBase);
    dCustom.swap(cmp_dCustom);
    std::cout << std::endl << "======= TEST 42 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test size(), front(), back() and element comparison
    after swap() of different size deques (superior size) */
    dBase.insert(dBase.end(), 3, 4);
    dCustom.insert(dCustom.end(), 3, 4);
    dBase.swap(cmp_dBase);
    dCustom.swap(cmp_dCustom);
    std::cout << std::endl << "======= TEST 43 =======" << std::endl;
    testBasics(dBase, dCustom);


    /* Test normal iterators */
    dBase.clear();
    dCustom.clear();
    for (int count = 0; count < 10; count++)
    {
        dBase.push_back(count);
        dCustom.push_back(count);
    }
    std::cout << std::endl << "======= TEST 44 =======" << std::endl;
    testIterator(dBase, dCustom);


   /* Test reverse iterators */

    std::cout << std::endl << "======= TEST 45 =======" << std::endl;
    testReverseIterator(dBase, dCustom);


    /* Test iterator constructor */
    std::deque<T> itBaseDeque(dBase.begin(), dBase.end());
    ft::Deque<T> itCustomDeque(dCustom.begin(), dCustom.end());
    std::cout << std::endl << "======= TEST 46 =======" << std::endl;
    testBasics(itBaseDeque, itCustomDeque);
}

void testDeques()
{
    std::cout <<  std::endl << "\033[38;5;202m******************************************************" << std::endl;
    std::cout << "***************        TEST DEQUE       **************" << std::endl;
    std::cout << "******************************************************\033[0m" << std::endl;
    testDeque<int>();
}