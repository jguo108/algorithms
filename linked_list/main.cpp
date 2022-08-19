#include "lc_list.h"

using namespace lc;


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 206: { // Reverse list
            LinkedList list1;
            list1.insert(1);
            list1.insert(2);
            list1.insert(3);
            list1.insert(4);
            list1.insert(5);
            list1.insert(6);
            list1.insert(7);
            list1.insert(8);
            list1.print();

            list1.r_reverse();
            list1.print();
        } break;
        case 25: { // Reverse k group TODO
            LinkedList list;
            list.insert(1);
            list.insert(2);
            list.insert(3);
            list.insert(4);
            list.insert(5);
            list.insert(6);
            list.insert(7);
            list.insert(8);
            list.print();
            list.reverse_k_group(2);
            list.print();
        } break;
        case 21: { // Merge two sorted lists
            LinkedList list1;
            list1.append(1);
            list1.append(5);
            list1.append(10);
            list1.append(15);
            list1.append(19);
            list1.append(40);
            list1.append(56);
            list1.append(99);
            list1.print();

            LinkedList list2;
            list2.append(2);
            list2.append(3);
            list2.append(13);
            list2.append(30);
            list2.append(100);
            list2.append(101);
            list2.print();

            LinkedList *result = merge_sorted_list(&list1, &list2);
            result->print();
        } break;
        
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }

    return 0;
}

