#include <queue>
#include "../includes/adaptor_containers/Queue.hpp"
#include "test.hpp"

template <typename T>
void testBasics(std::queue<T> qBase, ft::Queue<T> qCustom)
{
    (qBase.size() == qCustom.size()) ? fOK("size()") : fKO("size()");
    (qBase.front() == qCustom.front()) ? fOK("front()") : fKO("front()");
    (qBase.back() == qCustom.back()) ? fOK("back()") : fKO("back()");
}

template <typename T>
void testRelationalOperators(std::queue<T> qBase, std::queue<T> cmp_qBase,
                            ft::Queue<T> qCustom, ft::Queue<T> cmp_qCustom)
{
    ((qBase == cmp_qBase) == (qCustom == cmp_qCustom)) ? fOK("==") : fKO("==");
    ((qBase != cmp_qBase) == (qCustom != cmp_qCustom)) ? fOK("!=") : fKO("!=");
    ((qBase < cmp_qBase) == (qCustom < cmp_qCustom)) ? fOK("<") : fKO("<");
    ((qBase <= cmp_qBase) == (qCustom <= cmp_qCustom)) ? fOK("<=") : fKO("<=");
    ((qBase > cmp_qBase) == (qCustom > cmp_qCustom)) ? fOK(">") : fKO(">");
    ((qBase >= cmp_qBase) == (qCustom >= cmp_qCustom)) ? fOK(">=") : fKO(">=");
}

template <typename T>
void testQueue(void)
{
    std::queue<T> qBase;
    ft::Queue<T> qCustom;

    /* Test size() at initialization */
    std::cout << std::endl << "======= TEST 1 =======" << std::endl;
    (qBase.size() == qCustom.size()) ? fOK("size()") : fKO("size()");


    /* Test size() and top() after push() */
    qBase.push(10);
    qCustom.push(10);
    std::cout << std::endl << "======= TEST 2 =======" << std::endl;
    testBasics(qBase, qCustom);


    /* Test size() and top() after push() */
    qBase.pop();
    qCustom.pop();
    std::cout << std::endl << "======= TEST 3 =======" << std::endl;
    (qBase.size() == qCustom.size()) ? fOK("size()") : fKO("size()");


    /* Test relational operators with identical queues */
    qBase.push(10);
    qCustom.push(10);
    std::queue<T> cmp_qBase(qBase);
    ft::Queue<T> cmp_qCustom(qCustom);
    std::cout << std::endl << "======= TEST 4 =======" << std::endl;
    testRelationalOperators(qBase, cmp_qBase, qCustom, cmp_qCustom);


    /* Test size() and top() with not identical queues */
    qBase.push(10);
    qCustom.push(10);
    std::cout << std::endl << "======= TEST 5 =======" << std::endl;
    testRelationalOperators(qBase, cmp_qBase, qCustom, cmp_qCustom);
}

void testQueues()
{
    std::cout <<  std::endl << "\033[38;5;202m******************************************************" << std::endl;
    std::cout << "***************        TEST QUEUE       **************" << std::endl;
    std::cout << "******************************************************\033[0m" << std::endl;
    testQueue<int>();
}