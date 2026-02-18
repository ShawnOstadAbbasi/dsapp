#include <iostream>
#include "../include/data_structures/sequence_containers/singly_linked.hpp"

int main() {
    dsapp::singly_linked<int> list;
    list.push_back(1);
    //std::cout << list << std::endl;
    list.push_back(2);
    //std::cout << list << std::endl;

    list.push_back(3);
    list.push_back(4);

    //std::cout << list << std::endl;

    dsapp::singly_linked<int> list2 = list;
    std::cout << "list head address: " << list.getHead() << std::endl;
    std::cout << "list2 head address: " << list2.getHead() << std::endl;
    std::cout << list << std::endl;
    std::cout << list2 << std::endl;

    list2.pop_back();
    std::cout << list2 << std::endl;
    list2.pop_back();
    std::cout << list2 << std::endl;

    list2.push_front(25);
    std::cout << list2 << std::endl;

    list2.pop_font();
    std::cout << list2 << std::endl;

    list = list2;
    std::cout << "List address " << &list << ", " << list << std::endl;
    std::cout << "List2 address " << &list2 << ", " << list2 << std::endl;

    std::cout << "DONE" << std::endl;

    return 0;
}
