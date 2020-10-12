#include "sllist.h"

int main()
{
    SLList < int > list;
    SLList <int>::debug_mode = false;
    std::cout << list << std::endl;
    list.push_front(5);
    list.push_front(6);
    std::cout << list << std::endl;
    list.push_back(10);
    std::cout << list << ' ' << list.size() << std::endl;
    std::cout << list[1] << std::endl;
    return 0;
}
