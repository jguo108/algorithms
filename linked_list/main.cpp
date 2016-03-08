
#include "ll_list.h"

int main()
{
    ll::LinkedList<int> list;

    list.insert(101);
    list.insert(0);
    list.insert(101);
    list.insert(99);
    list.insert(54);
    list.insert(101);
    list.insert(231);
    list.insert(101);

    list.print();

    list.r_reverse();

    list.print();

    return 0;
}

