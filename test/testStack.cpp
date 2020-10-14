#include <stack>
#include "../includes/adaptor_containers/Stack.hpp"
#include "test.hpp"

template <typename T>
void testBasics(std::stack<T> sBase, ft::Stack<T> sCustom)
{
    (sBase.size() == sCustom.size()) ? fOK("size()") : fKO("size()");
    (sBase.top() == sCustom.top()) ? fOK("top()") : fKO("top()");
}

template <typename T>
void testRelationalOperators(std::stack<T> sBase, std::stack<T> cmp_sBase,
                            ft::Stack<T> sCustom, ft::Stack<T> cmp_sCustom)
{
    ((sBase == cmp_sBase) == (sCustom == cmp_sCustom)) ? fOK("==") : fKO("==");
    ((sBase != cmp_sBase) == (sCustom != cmp_sCustom)) ? fOK("!=") : fKO("!=");
    ((sBase < cmp_sBase) == (sCustom < cmp_sCustom)) ? fOK("<") : fKO("<");
    ((sBase <= cmp_sBase) == (sCustom <= cmp_sCustom)) ? fOK("<=") : fKO("<=");
    ((sBase > cmp_sBase) == (sCustom > cmp_sCustom)) ? fOK(">") : fKO(">");
    ((sBase >= cmp_sBase) == (sCustom >= cmp_sCustom)) ? fOK(">=") : fKO(">=");
}

template <typename T>
void testStack(void)
{
    std::stack<T> sBase;
    ft::Stack<T> sCustom;

    /* Test size() at initialization */
    std::cout << std::endl << "======= TEST 1 =======" << std::endl;
    (sBase.size() == sCustom.size()) ? fOK("size()") : fKO("size()");


    /* Test size() and top() after push() */
    sBase.push(10);
    sCustom.push(10);
    std::cout << std::endl << "======= TEST 2 =======" << std::endl;
    testBasics(sBase, sCustom);


    /* Test size() and top() after push() */
    sBase.pop();
    sCustom.pop();
    std::cout << std::endl << "======= TEST 3 =======" << std::endl;
    (sBase.size() == sCustom.size()) ? fOK("size()") : fKO("size()");


    /* Test relational operators with identical stacks */
    sBase.push(10);
    sCustom.push(10);
    std::stack<T> cmp_sBase(sBase);
    ft::Stack<T> cmp_sCustom(sCustom);
    std::cout << std::endl << "======= TEST 4 =======" << std::endl;
    testRelationalOperators(sBase, cmp_sBase, sCustom, cmp_sCustom);


    /* Test size() and top() with not identical stacks */
    sBase.push(10);
    sCustom.push(10);
    std::cout << std::endl << "======= TEST 5 =======" << std::endl;
    testRelationalOperators(sBase, cmp_sBase, sCustom, cmp_sCustom);
}

void testStacks()
{
    std::cout <<  std::endl << "\033[38;5;202m******************************************************" << std::endl;
    std::cout << "***************        TEST STACK       **************" << std::endl;
    std::cout << "******************************************************\033[0m" << std::endl;
    testStack<int>();
}