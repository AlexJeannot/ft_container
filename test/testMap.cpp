#include <map>
#include "../includes/associative_containers/Map.hpp" 
#include "test.hpp"

template <typename Key, typename V>
void testBasics(const std::map<Key, V>& mBase, const ft::Map<Key, V>& mCustom)
{
    (mBase.size() == mCustom.size()) ? fOK("size()") : fKO("size()");
    typename std::map<Key, V>::const_iterator itBase = mBase. begin();
    typename ft::Map<Key, V>::const_iterator itCustom = mCustom.cbegin();
    if (mCustom.size() > 0)
    {
        while (itBase != mBase.end() && itCustom != mCustom.end())
        {
            if (itBase->first != itCustom->first
            || itBase->second != itCustom->second)
            {
                fKO("map's elements comparison");
                break;
            }
            itBase++;
            itCustom++;
        }
        if (itBase != mBase.end() || itCustom != mCustom.end())
            fKO("map's elements number");
        else
            fOK("map's elements number");
    }
}

template <typename Key, typename V>
void testRelationalOperators(const std::map<Key, V>& mBase, const std::map<Key, V>& cmp_mBase,
                            const ft::Map<Key, V>& mCustom, const ft::Map<Key, V>& cmp_mCustom)
{
    ((mBase == cmp_mBase) == (mCustom == cmp_mCustom)) ? fOK("==") : fKO("==");
    ((mBase != cmp_mBase) == (mCustom != cmp_mCustom)) ? fOK("!=") : fKO("!=");
    ((mBase < cmp_mBase) == (mCustom < cmp_mCustom)) ? fOK("<") : fKO("<");
    ((mBase <= cmp_mBase) == (mCustom <= cmp_mCustom)) ? fOK("<=") : fKO("<=");
    ((mBase > cmp_mBase) == (mCustom > cmp_mCustom)) ? fOK(">") : fKO(">");
    ((mBase >= cmp_mBase) == (mCustom >= cmp_mCustom)) ? fOK(">=") : fKO(">=");
}

template <typename Key, typename V>
void testIterator(std::map<Key, V> mBase, ft::Map<Key, V> mCustom)
{
    bool verif = true;
    typename std::map<Key, V>::iterator itBase;
    typename ft::Map<Key, V>::iterator itCustom;
    itBase = mBase.begin();
    itCustom = mCustom.begin();

    (mBase.begin()->first == mCustom.begin()->first) ? fOK("begin()") : fKO("begin()");
    ((mBase.cbegin())->first == (mCustom.cbegin())->first) ? fOK("cbegin()") : fKO("cbegin()");
    ((--mBase.end())->first == (--mCustom.end())->first) ? fOK("end()") : fKO("end()");
    ((--mBase.cend())->first == (--mCustom.cend())->first) ? fOK("cend()") : fKO("cend()");

    while (itBase != mBase.end())
    {
        if ((itBase++)->first != (itCustom++)->first)
        {
            if (itBase != mBase.end())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    itBase = --mBase.end();
    itCustom = --mCustom.end();
    while (itBase != mBase.begin())
    {
        if ((itBase--)->first != (itCustom--)->first)
        {
            if (itBase != mBase.begin())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator--(int)") : fKO("Operator--(int)");

    verif = true;
    itBase = mBase.begin();
    itCustom = mCustom.begin();
    while (itBase != mBase.end())
    {
        if ((++itBase)->first != (++itCustom)->first)
        {
            if (itBase != mBase.end())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    verif = true;
    itBase = mBase.end();
    itCustom = mCustom.end();
    while (itBase != mBase.begin())
    {
        if ((--itBase)->first != (--itCustom)->first)
        {
            if (itBase != mBase.begin())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator--()") : fKO("Operator--()");

    ((mBase.begin() == mBase.begin()) == (mCustom.begin() == mCustom.begin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((mBase.begin() != mBase.begin()) == (mCustom.begin() != mCustom.begin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
}


template <typename Key, typename V>
void testReverseIterator(std::map<Key, V> mBase, ft::Map<Key, V> mCustom)
{
    bool verif = true;
    typename std::map<Key, V>::reverse_iterator itBase;
    typename ft::Map<Key, V>::reverse_iterator itCustom;
    itBase = mBase.rbegin();
    itCustom = mCustom.rbegin();

    (mBase.rbegin()->first == mCustom.rbegin()->first) ? fOK("rbegin()") : fKO("rbegin()");
    ((mBase.crbegin())->first == (mCustom.crbegin())->first) ? fOK("crbegin()") : fKO("crbegin()");
    ((--mBase.rend())->first == (--mCustom.rend())->first) ? fOK("rend()") : fKO("rend()");
    ((--mBase.crend())->first == (--mCustom.crend())->first) ? fOK("crend()") : fKO("crend()");

    while (itBase != mBase.rend())
    {
        if ((itBase++)->first != (itCustom++)->first)
        {
            if (itBase != mBase.rend())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    itBase = --mBase.rend();
    itCustom = --mCustom.rend();
    while (itBase != mBase.rbegin())
    {
        if ((itBase--)->first != (itCustom--)->first)
        {
            if (itBase != mBase.rbegin())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator--(int)") : fKO("Operator--(int)");

    verif = true;
    itBase = mBase.rbegin();
    itCustom = mCustom.rbegin();
    while (itBase != --mBase.rend())
    {
        if ((++itBase)->first != (++itCustom)->first)
        {
            if (itBase != mBase.rend())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    verif = true;
    itBase = mBase.rend();
    itCustom = mCustom.rend();
    while (itBase != mBase.rbegin())
    {
        if ((--itBase)->first != (--itCustom)->first)
        {
            if (itBase != mBase.rbegin())
                verif = false;
        }
    }
    (verif == true) ? fOK("Operator--()") : fKO("Operator--()");

    ((mBase.begin() == mBase.begin()) == (mCustom.begin() == mCustom.begin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((mBase.begin() != mBase.begin()) == (mCustom.begin() != mCustom.begin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
}


template <typename Key, typename V>
void testMap(void)
{
    std::map<Key, V> mBase;
    ft::Map<Key, V> mCustom;


    /* Test size() and element comparison at initialization */
    std::cout << std::endl << "======= TEST 1 =======" << std::endl;
    testBasics(mBase, mCustom);


    /* Test max_size() */
    std::cout << std::endl << "======= TEST 2 =======" << std::endl;
    (mBase.max_size() == mCustom.max_size()) ? fOK("max_size()") : fKO("max_size()");


    /* Test size() and element comparison after insert one elem */
    std::pair<typename std::map<Key, V>::iterator, bool> basePair;
    ft::pair<typename ft::Map<Key, V>::iterator, bool> customPair;
    basePair = mBase.insert(std::make_pair<Key, V>(1, 20));
    customPair = mCustom.insert(ft::make_pair<Key, V>(1, 20));
    std::cout << std::endl << "======= TEST 3 =======" << std::endl;
    testBasics(mBase, mCustom);
    (basePair.first->first == customPair.first->first) ? fOK("key pair returned") : fKO("key pair returned");
    (basePair.second == customPair.second) ? fOK("bool returned") : fKO("bool returned");


    /* Test size() and element comparison after insert one existing elem */
    basePair = mBase.insert(std::make_pair<Key, V>(1, 20));
    customPair = mCustom.insert(ft::make_pair<Key, V>(1, 20));
    std::cout << std::endl << "======= TEST 4 =======" << std::endl;
    testBasics(mBase, mCustom);
    (basePair.first->first == customPair.first->first) ? fOK("key pair returned") : fKO("key pair returned");
    (basePair.second == customPair.second) ? fOK("bool returned") : fKO("bool returned");


    /* Test size() and element comparison after insert one elem with position */
    typename std::map<Key, V>::iterator itBase;
    typename ft::Map<Key, V>::iterator itCustom;
    itBase = mBase.insert(mBase.begin(), std::make_pair<Key, V>(2, 20));
    itCustom = mCustom.insert(mCustom.begin(), ft::make_pair<Key, V>(2, 20));
    std::cout << std::endl << "======= TEST 5 =======" << std::endl;
    testBasics(mBase, mCustom);
    (itBase->first == itCustom->first) ? fOK("key pair returned") : fKO("key pair returned");


    /* Test size() and element comparison after insert one existing elem with position */
    itBase = mBase.insert(mBase.begin(), std::make_pair<Key, V>(2, 20));
    itCustom = mCustom.insert(mCustom.begin(), ft::make_pair<Key, V>(2, 20));
    std::cout << std::endl << "======= TEST 6 =======" << std::endl;
    testBasics(mBase, mCustom);
    (itBase->first == itCustom->first) ? fOK("key pair returned") : fKO("key pair returned");


    /* Test size() and element comparison after insert range of elem */
    std::map<Key, V> mBase2;
    mBase2.insert(std::make_pair<Key, V>(33, 33));
    mBase2.insert(std::make_pair<Key, V>(44, 44));
    mBase2.insert(std::make_pair<Key, V>(55, 55));
    mBase2.insert(std::make_pair<Key, V>(66, 66));
    mBase.insert(mBase2.begin(), mBase2.end());
    mCustom.insert(mBase2.begin(), mBase2.end());
    std::cout << std::endl << "======= TEST 7 =======" << std::endl;
    testBasics(mBase, mCustom);


    /* Test empty(), size() and element comparison with multiple elems */
    std::cout << std::endl << "======= TEST 8 =======" << std::endl;
    testBasics(mBase, mCustom);
    (mBase.empty() == mCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty(), size() and element comparison after erase() one elem by iterator */
    mBase.erase(mBase.begin());
    mCustom.erase(mCustom.begin());
    std::cout << std::endl << "======= TEST 9 =======" << std::endl;
    testBasics(mBase, mCustom);
    (mBase.empty() == mCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty(), size() and element comparison after erase() one elem by existing key */
    mBase.erase(33);
    mCustom.erase(33);
    std::cout << std::endl << "======= TEST 10 =======" << std::endl;
    testBasics(mBase, mCustom);
    (mBase.empty() == mCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty(), size() and element comparison after erase() one elem by no existing key */
    mBase.erase(99);
    mCustom.erase(99);
    std::cout << std::endl << "======= TEST 11 =======" << std::endl;
    testBasics(mBase, mCustom);
    (mBase.empty() == mCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty(), size() and element comparison after erase() by range */
    mBase.erase(mBase.begin(), mBase.end());
    mCustom.erase(mCustom.begin(), mCustom.end());
    std::cout << std::endl << "======= TEST 12 =======" << std::endl;
    testBasics(mBase, mCustom);
    (mBase.empty() == mCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty(), size() and element comparison after clear() */
    mBase.insert(mBase2.begin(), mBase2.end());
    mCustom.insert(mBase2.begin(), mBase2.end());
    mBase.clear();
    mCustom.clear();
    std::cout << std::endl << "======= TEST 13 =======" << std::endl;
    testBasics(mBase, mCustom);
    (mBase.empty() == mCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test return key_comp() */
    typename std::map<Key, V>::key_compare compBase;
    typename ft::Map<Key, V>::key_compare compCustom;
    mBase.insert(mBase2.begin(), mBase2.end());
    mCustom.insert(mBase2.begin(), mBase2.end());
    compBase = mBase.key_comp();
    compCustom = mCustom.key_comp();
    std::cout << std::endl << "======= TEST 13 =======" << std::endl;
    (compBase(1, 2) == compCustom(1, 2)) ? fOK("key_comp()") : fKO("key_comp()");


    /* Test return key_comp() */
    std::cout << std::endl << "======= TEST 14 =======" << std::endl;
    (mBase.key_comp()('a', 'g') == mCustom.key_comp()('a', 'g')) ? fOK("value_comp()") : fKO("value_comp()");


    /* Test returned iterator from find() with existing key */
    itBase = mBase.find(33);
    itCustom = mCustom.find(33);
    std::cout << std::endl << "======= TEST 15 =======" << std::endl;
    testBasics(mBase, mCustom);
    (itBase->first == itCustom->first) ? fOK("find()") : fKO("find()");


    /* Test returned iterator from find() with not existing key */
    itBase = mBase.find(99);
    itCustom = mCustom.find(99);
    std::cout << std::endl << "======= TEST 16 =======" << std::endl;
    testBasics(mBase, mCustom);
    (itCustom == mCustom.end()) ? fOK("find()") : fKO("find()");


    /* Test returned size_t from count() with existing key */
    std::cout << std::endl << "======= TEST 17 =======" << std::endl;
    (mBase.count(33) == mCustom.count(33)) ? fOK("count()") : fKO("count()");


    /* Test returned size_t from count() with not existing key */
    std::cout << std::endl << "======= TEST 18 =======" << std::endl;
    (mBase.count(99) == mCustom.count(99)) ? fOK("count()") : fKO("count()");


    /* Test returned iterator from lower_bound() with lowest key */
    std::cout << std::endl << "======= TEST 19 =======" << std::endl;
    (mBase.lower_bound(20)->first == mCustom.lower_bound(20)->first) ? fOK("lower_bound()") : fKO("lower_bound()");
    

    /* Test returned iterator from lower_bound() with exact key */
    std::cout << std::endl << "======= TEST 20 =======" << std::endl;
    (mBase.lower_bound(44)->first == mCustom.lower_bound(44)->first) ? fOK("lower_bound()") : fKO("lower_bound()");
    

    /* Test returned iterator from lower_bound() with middle key */
    std::cout << std::endl << "======= TEST 21 =======" << std::endl;
    (mBase.lower_bound(50)->first == mCustom.lower_bound(50)->first) ? fOK("lower_bound()") : fKO("lower_bound()");
    
    
    /* Test returned iterator from lower_bound() with no existing key */
    std::cout << std::endl << "======= TEST 22 =======" << std::endl;
    (mCustom.lower_bound(99) == mCustom.end()) ? fOK("lower_bound()") : fKO("lower_bound()");
    
    
    /* Test returned iterator from upper_bound() with lowest key */
    std::cout << std::endl << "======= TEST 23 =======" << std::endl;
    (mBase.upper_bound(20)->first == mCustom.upper_bound(20)->first) ? fOK("upper_bound()") : fKO("upper_bound()");


    /* Test returned iterator from upper_bound() with exact key */
    std::cout << std::endl << "======= TEST 24 =======" << std::endl;
    (mBase.upper_bound(44)->first == mCustom.upper_bound(44)->first) ? fOK("upper_bound()") : fKO("upper_bound()");
    

    /* Test returned iterator from upper_bound() with middle key */
    std::cout << std::endl << "======= TEST 25 =======" << std::endl;
    (mBase.upper_bound(50)->first == mCustom.upper_bound(50)->first) ? fOK("upper_bound()") : fKO("upper_bound()");
    
    
    /* Test returned iterator from upper_bound() with no existing key */
    std::cout << std::endl << "======= TEST 26 =======" << std::endl;
    (mCustom.upper_bound(99) == mCustom.end()) ? fOK("upper_bound()") : fKO("upper_bound()");


    /* Test returned iterator from equal_range() with lowest key */
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    (mBase.equal_range(20).first->first == mCustom.equal_range(20).first->first
    && mBase.equal_range(20).second->first == mCustom.equal_range(20).second->first) ? fOK("equal_range()") : fKO("equal_range()");


    /* Test returned iterator from equal_range() with exact key */
    std::cout << std::endl << "======= TEST 28 =======" << std::endl;
    (mBase.equal_range(44).first->first == mCustom.equal_range(44).first->first
    && mBase.equal_range(44).second->first == mCustom.equal_range(44).second->first) ? fOK("equal_range()") : fKO("equal_range()");
    

    /* Test returned iterator from equal_range() with middle key */
    std::cout << std::endl << "======= TEST 29 =======" << std::endl;
    (mBase.equal_range(50).first->first == mCustom.equal_range(50).first->first
    && mBase.equal_range(50).second->first == mCustom.equal_range(50).second->first) ? fOK("equal_range()") : fKO("equal_range()");
    
    
    /* Test returned iterator from equal_range() with no existing key */
    std::cout << std::endl << "======= TEST 30 =======" << std::endl;
    (mCustom.equal_range(99).first == mCustom.end()
    && mCustom.equal_range(99).second == mCustom.end()) ? fOK("equal_range()") : fKO("equal_range()");


    /* Test relationals operators with identical maps */
    std::map<Key, V> cmp_mBase(mBase);
    ft::Map<Key, V> cmp_mCustom(mCustom);
    std::cout << std::endl << "======= TEST 31 =======" << std::endl;
    testRelationalOperators(mBase, cmp_mBase, mCustom, cmp_mCustom);


    /* Test relationals operators with not identical maps */
    cmp_mBase.insert(std::make_pair(17, 40));
    cmp_mCustom.insert(ft::make_pair(17, 40));
    std::cout << std::endl << "======= TEST 32 =======" << std::endl;
    testRelationalOperators(mBase, cmp_mBase, mCustom, cmp_mCustom);


    /* Test size() and map elements comparison after swap */
    mBase.swap(cmp_mBase);
    mCustom.swap(cmp_mCustom);
    std::cout << std::endl << "======= TEST 33 =======" << std::endl;
    testBasics(mBase, mCustom);


    /* Test iterators */
    mBase.insert(std::make_pair(4, 1));
    mBase.insert(std::make_pair(15, 1));
    mBase.insert(std::make_pair(22, 1));
    mBase.insert(std::make_pair(10, 1));
    mCustom.insert(ft::make_pair(4, 1));
    mCustom.insert(ft::make_pair(15, 1));
    mCustom.insert(ft::make_pair(22, 1));
    mCustom.insert(ft::make_pair(10, 1));
    std::cout << std::endl << "======= TEST 34 =======" << std::endl;
    testIterator(mBase, mCustom);


    /* Test reverse iterators */
    std::cout << std::endl << "======= TEST 35 =======" << std::endl;
    testReverseIterator(mBase, mCustom);


    /* Test iterator constructor */
    std::map<Key, V> itBaseMap(mBase.begin(), mBase.end());
    ft::Map<Key, V> itCustomMap(mCustom.begin(), mCustom.end());
    std::cout << std::endl << "======= TEST 36 =======" << std::endl;
    testBasics(itBaseMap, itCustomMap);
}


void testMaps()
{
    std::cout <<  std::endl << "\033[38;5;202m******************************************************" << std::endl;
    std::cout << "***************         TEST MAP        **************" << std::endl;
    std::cout << "******************************************************\033[0m" << std::endl;
    testMap<int, char>();
}