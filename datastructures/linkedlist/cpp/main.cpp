#include <iostream>
#include "linkedlist.hpp"

int main() {
    auto ll = LinkedList<int>(10, 2); 
    
    std::cout << ll.size() << "\n";
    std::cout << ll.string() << "\n";

    ll.append(1337);
    std::cout << ll.size() << "\n";
    std::cout << ll.string() << "\n";

    ll.append(12);
    ll.append(67);
    ll.append(69);
    std::cout << ll.string() << "\n";
    
    ll.remove(11);
    std::cout << ll.string() << "\n";
}
