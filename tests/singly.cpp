#include <iostream>
#include "../include/data_structures/sequence_containers/singly_linked.hpp"

int main() {
    dsapp::singly_linked<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    dsapp::singly_linked<int> list2 = list;

    std::cout << list << std::endl;
    std::cout << list2 << std::endl;

    list.push_front(15);
    list.push_back(50);

    list2.pop_back();

    std::cout << "\n";
    std::cout << list << std::endl;
    std::cout << list2 << std::endl;

    list.getHead()->getNext()->setValue(99);
    list.getHead()->getNext()->getNext()->setValue(666);

    std::cout << "\n";
    std::cout << list << std::endl;
    std::cout << list2 << std::endl;

    list2.pop_front();
    list2.pop_front();
    list2.pop_front();

    std::cout << "\n";
    std::cout << list << std::endl;
    std::cout << list2 << std::endl;

    std::cout << "\nNOW INSERTING\n";
    list.insert(49, 0);
    std::cout << list << std::endl;
    list.insert(34, 4);
    std::cout << list << std::endl;
    list.insert(78, 7);
    std::cout << list << std::endl;
    list.insert(999, 10);
    std::cout << list << std::endl;
    list.insert(555, -1);
    std::cout << list << std::endl;

    std::cout << "\nNOW REMOVING\n";

    list.remove(-1);
    std::cout << list << std::endl;
    list.remove(32);
    std::cout << list << std::endl;
    list.remove(0);
    std::cout << list << std::endl;
    list.remove(1);
    std::cout << list << std::endl;
    list.remove(3);
    std::cout << list << std::endl;
    list.remove(5);
    std::cout << list << std::endl;

    std::cout << "\nINDEXING" << std::endl;
    std::cout << list[0] << std::endl;
    list[0] = 37;
    std::cout << list << std::endl;

    std::cout << "\nREVERSE" << std::endl;
    list.reverse();
    std::cout << list << std::endl;

    list.pop_back();
    list.pop_back();
    std::cout << list << std::endl;
    list.reverse();
    std::cout << list << std::endl;

    std::cout << "\nREMOVE" << std::endl; 
    list.remove(-1);
    std::cout << list << std::endl;
    list.remove(89);
    std::cout << list << std::endl;
    list.remove(1);
    std::cout << list << std::endl;
    list.remove(1);
    std::cout << list << std::endl;
    list.remove(0);
    std::cout << list << std::endl;


    return 0;
}
