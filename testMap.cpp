#include <iostream>
#include <map>

#include "includes/associative_containers/Map.hpp" 
#include "includes/associative_containers/Tree.hpp"
#include "includes/iterators/MapIterator.hpp"
#include "test.cpp"

int main()
{
    std::pair<int, int> p(99, 77);
    std::cout << std::get<0>(p) << std::endl;
    std::pair<char, char> p2;
    p2 = p;
    std::cout << std::get<0>(p2) << std::endl;

    std::cout << "========\n";

    std::map<int, int> m1;

    m1.insert(p);
    std::cout << m1[99] << std::endl;
    std::pair<int, int> j(120, 120);
    m1.insert(j);
    std::cout << "========\n";
    for (std::map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
        std::cout << it->first << std::endl;

    m1.insert(std::make_pair(5, 5));


    std::cout << "========\n";

    for (std::map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
        std::cout << it->first << std::endl;

    std::cout << "======== START MY TREE ========\n";

    ft::Tree<int, int> my_tree;
    ft::pair<int, int> my_pair0(0, 1);
    ft::pair<int, int> my_pair1(1, 1);
    ft::pair<int, int> my_pair2(2, 1);
    ft::pair<int, int> my_pair3(3, 1);
    ft::pair<int, int> my_pair4(4, 1);
    ft::pair<int, int> my_pair5(5, 1);
    ft::pair<int, int> my_pair6(6, 1);
    ft::pair<int, int> my_pair7(7, 1);
    ft::pair<int, int> my_pair8(8, 1);
    ft::pair<int, int> my_pair9(9, 1);
    ft::pair<int, int> my_pair10(10, 1);
    ft::pair<int, int> my_pair11(11, 1);
    ft::pair<int, int> my_pair12(12, 1);
    ft::pair<int, int> my_pair13(13, 1);
    ft::pair<int, int> my_pair14(14, 1);
    ft::pair<int, int> my_pair15(15, 1);
    ft::pair<int, int> my_pair16(16, 1);
    ft::pair<int, int> my_pair17(17, 1);
    ft::pair<int, int> my_pair18(18, 1);
    ft::pair<int, int> my_pair19(19, 1);
    ft::pair<int, int> my_pair20(20, 1);
    ft::pair<int, int> my_pair21(21, 1);
    ft::pair<int, int> my_pair22(22, 1);
    ft::pair<int, int> my_pair23(23, 1);
    ft::pair<int, int> my_pair24(24, 1);
    ft::pair<int, int> my_pair25(25, 1);


    //my_tree.createNode(my_pair1);
    //my_tree.createNode(my_pair2);
    //my_tree.createNode(my_pair3);
    //my_tree.createNode(my_pair4);
    //my_tree.createNode(my_pair5);

    /*
    my_tree.createNode(my_pair6);
    my_tree.createNode(my_pair7);
    my_tree.createNode(my_pair8);
    my_tree.createNode(my_pair9);
    my_tree.createNode(my_pair10);
    my_tree.createNode(my_pair11);
    my_tree.createNode(my_pair12);
    my_tree.createNode(my_pair13);
    my_tree.createNode(my_pair14);
    my_tree.createNode(my_pair15);
    my_tree.createNode(my_pair16);
    my_tree.createNode(my_pair17);
*/

    my_tree.displayTree();
/*
    std::cout << "-------- TEST CUSTOM IT -------\n";

    ft::Map<int, int>::iterator it(my_tree.begin());
    it--;
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;
    it++;
    std::cout << it->first << std::endl;
    std::cout << "-------- TEST border -------\n";
    std::cout << my_tree.keySearch(1)->getLeft() << std::endl;
    std::cout << my_tree.keySearch(5)->getRight() << std::endl;

    std::cout << "-------- TEST add border key -------\n";
    my_tree.createNode(my_pair0);
    my_tree.displayTree();
*/



/* TEST DELETE ROOT
    std::cout << "-------- DISPLAY TREE -------\n";
    my_tree.displayTree();

    std::cout << "-------- RESULT KEY SEARCH -------\n";
    std::cout << my_tree.keySearch(1) << std::endl;

    my_tree.DeleteNode(my_tree.keySearch(10));
    std::cout << "-------- DISPLAY TREE APRES DELETE ROOT NULL -------\n";
    my_tree.displayTree();

    my_tree.createNode(my_pair10);
    my_tree.DeleteNode(my_tree.keySearch(10));
    std::cout << "-------- DISPLAY TREE APRES DELETE ROOT NO CHILD -------\n";
    my_tree.displayTree();

    my_tree.createNode(my_pair10);
    my_tree.createNode(my_pair5);
    my_tree.DeleteNode(my_tree.keySearch(10));
    std::cout << "-------- DISPLAY TREE APRES DELETE ROOT LEFT CHILD -------\n";
    my_tree.displayTree();

    my_tree.createNode(my_pair10);
    my_tree.DeleteNode(my_tree.keySearch(5));
    std::cout << "-------- DISPLAY TREE APRES DELETE ROOT RIGHT CHILD -------\n";
    my_tree.displayTree();

    my_tree.createNode(my_pair5);
    my_tree.createNode(my_pair15);
    my_tree.DeleteNode(my_tree.keySearch(10));
    std::cout << "-------- DISPLAY TREE APRES DELETE ROOT TWO CHILD ONE ELEM -------\n";
    my_tree.displayTree();

    my_tree.createNode(my_pair3);
    my_tree.createNode(my_pair2);
    my_tree.DeleteNode(my_tree.keySearch(5));
    std::cout << "-------- DISPLAY TREE APRES DELETE ROOT TWO CHILD LEFT BRANCH -------\n";
    my_tree.displayTree();


    my_tree.DeleteNode(my_tree.keySearch(2));
    my_tree.DeleteNode(my_tree.keySearch(3));
    my_tree.DeleteNode(my_tree.keySearch(15));
    my_tree.createNode(my_pair10);
    my_tree.createNode(my_pair15);
    my_tree.createNode(my_pair5);
    my_tree.createNode(my_pair3);
    my_tree.createNode(my_pair2);
    my_tree.createNode(my_pair1);


    my_tree.DeleteNode(my_tree.keySearch(10));
    std::cout << "-------- DISPLAY TREE APRES DELETE FOUR COMPLETE TREE -------\n";
    my_tree.displayTree();

    my_tree.DeleteNode(my_tree.keySearch(1));
    my_tree.DeleteNode(my_tree.keySearch(2));
    my_tree.DeleteNode(my_tree.keySearch(3));
    my_tree.DeleteNode(my_tree.keySearch(5));
    my_tree.DeleteNode(my_tree.keySearch(15));
    my_tree.createNode(my_pair10);
    my_tree.createNode(my_pair15);
    my_tree.createNode(my_pair5);

    my_tree.createNode(my_pair1);
    my_tree.createNode(my_pair3);
    my_tree.createNode(my_pair4);

    my_tree.createNode(my_pair7);
    my_tree.createNode(my_pair6);
    my_tree.createNode(my_pair9);
    my_tree.createNode(my_pair8);

    my_tree.createNode(my_pair12);
    my_tree.createNode(my_pair11);
    my_tree.createNode(my_pair13);
    my_tree.createNode(my_pair14);

    my_tree.createNode(my_pair20);
    my_tree.createNode(my_pair17);
    my_tree.createNode(my_pair25);

    std::cout << "-------- DISPLAY TREE AVANT DELETE ROOT COMPLETE TREE -------\n";
    my_tree.displayTree();
    std::cout << ">>>>>>>>> AVANT DELETE\n";

    my_tree.DeleteNode(my_tree.keySearch(10));
    std::cout << "-------- DISPLAY TREE APRES DELETE ROOT ROOT CHILD LEFT BRANCH -------\n";
    my_tree.displayTree();
*/





/* TEST VRAI IT 
    std::cout << "======== START MAP IT ========\n";
    std::map<int,int> map;
    map.insert(std::make_pair(1, 4));
    map.insert(std::make_pair(5, 4));
    map.insert(std::make_pair(10, 4));
    map.insert(std::make_pair(33, 4));
    map.insert(std::make_pair(44, 4));

    std::map<int, int>::iterator it1 = map.begin();
    std::map<int, int>::iterator it2 = map.begin();
    std::cout << (++it1)->first << std::endl;
    std::cout << (it1++)->first << std::endl;
    std::cout << it1->first << std::endl;
    std::cout << (++it1)->first << std::endl;
    std::cout << (++it1)->first << std::endl;
    std::cout << (++it1)->first << std::endl;
    //std::cout << (it < it2) << std::endl;
*/













    my_tree.createNode(my_pair10);
    my_tree.createNode(my_pair5);
    my_tree.createNode(my_pair7);
    my_tree.createNode(my_pair6);
    my_tree.createNode(my_pair9);
    my_tree.createNode(my_pair8);
    my_tree.createNode(my_pair1);
    my_tree.createNode(my_pair3);
    my_tree.createNode(my_pair4);

    my_tree.createNode(my_pair15);
    my_tree.createNode(my_pair12);
    my_tree.createNode(my_pair11);
    my_tree.createNode(my_pair13);
    my_tree.createNode(my_pair14);
    my_tree.createNode(my_pair20);
    my_tree.createNode(my_pair17);
    my_tree.createNode(my_pair25);

    std::cout << "-------- DISPLAY TREE AVANT DELETE -------\n";
    my_tree.displayTree();

 // TEST DELETE NODE NOT ROOT 
 
    my_tree.DeleteNode(my_tree.keySearch(4));
    std::cout << "-------- DISPLAY TREE APRES DELETE 4 -------\n";
    my_tree.displayTree();
    std::cout << ">>>> FIN DISPLAY\n";

    std::cout << my_tree.keySearch(9) << std::endl;
    my_tree.DeleteNode(my_tree.keySearch(9));
    std::cout << "-------- DISPLAY TREE APRES DELETE 9 -------\n";
    my_tree.displayTree();
    std::cout << ">>>> FIN DISPLAY\n";

    my_tree.DeleteNode(my_tree.keySearch(13));
    std::cout << "-------- DISPLAY TREE APRES DELETE 13 -------\n";
    my_tree.displayTree();
    std::cout << ">>>> FIN DISPLAY\n";

    my_tree.DeleteNode(my_tree.keySearch(15));
    std::cout << "-------- DISPLAY TREE APRES DELETE 15 -------\n";
    my_tree.displayTree();
    std::cout << ">>>> FIN DISPLAY\n";

    my_tree.DeleteNode(my_tree.keySearch(1));
    std::cout << "-------- DISPLAY TREE APRES DELETE 1 -------\n";
    my_tree.displayTree();
    std::cout << ">>>> FIN DISPLAY\n";

    my_tree.DeleteNode(my_tree.keySearch(25));
    std::cout << "-------- DISPLAY TREE APRES DELETE 25 -------\n";
    my_tree.displayTree();
    std::cout << ">>>> FIN DISPLAY\n";


}