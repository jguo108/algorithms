
#include "ll_list.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 1: { // Merge two sorted lists
            ll::LinkedList<int> list1;
            list1.insert(104);
            list1.insert(78);
            list1.insert(4);

            ll::LinkedList<int> list2;
            list2.add(0);
            list2.add(11);
            list2.add(17);
            list2.add(34);
            list2.add(189);

            list1.print();
            list2.print();
            ll::LinkedList<int> result = mergeSortedLists(list1, list2);
            result.print();
        } break;
        case 2: { // Reverse sublsit
            ll::LinkedList<int> list;
            list.add(0);
            list.add(11);
            list.add(17);
            list.add(34);
            list.add(56);
            list.add(189);

            list.print();
            list.reverseSublist(0, 5);
            list.print();

        } break;
        case 3: { // 
            std::cerr << "Not implemented!" << std::endl;
        } break;
        case 4: { // 
            std::cerr << "Not implemented!" << std::endl;
        } break;
        case 5: { // 
            std::cerr << "Not implemented!" << std::endl;
        } break;
        case 6: { // 
            std::cerr << "Not implemented!" << std::endl;
        } break;
        case 7: { // Reverse sublsit
            ll::LinkedList<int> list;
            list.add(0);
            list.add(11);
            list.add(17);
            list.add(34);
            list.add(56);
            list.add(189);

            list.print();
            list.removeKthLastNode(8);
            list.print();
        } break;
        case 8: { // Remove duplicates 
            ll::LinkedList<int> list;
            list.add(0);
            list.add(11);
            list.add(11);
            list.add(11);
            list.add(17);
            list.add(34);
            list.add(56);
            list.add(56);
            list.add(56);
            list.add(89);
            list.add(189);
            list.add(189);
            list.add(189);

            list.print();
            list.removeDuplicates();
            list.print();
        } break;
        case 9: { // Right shift 
            ll::LinkedList<int> list;
            list.add(0);
            list.add(1);
            list.add(2);
            list.add(3);
            list.add(4);
            list.add(5);

            list.print();
            list.rightShift(6);
            list.print();
        } break;
        case 10: { // Even odd merge 
            ll::LinkedList<int> list;
            list.add(0);
            list.add(1);
            list.add(2);
            list.add(3);
            list.add(4);
            list.add(5);
            list.add(6);

            list.print();
            list.evenOddMerge();
            list.print();
        } break;
        case 11: { // Is palindromic 
            ll::LinkedList<int> list;
            list.add(0);
            list.add(1);
            list.add(2);
            list.add(3);
            list.add(3);
            list.add(2);
            list.add(1);
            list.add(0);

            list.print();
            std::cout << "Is palindromic: " << list.isPalindromic() << std::endl;
        } break;
        case 12: { // Even odd merge 
            ll::LinkedList<int> list;
            list.add(0);
            list.add(4);
            list.add(6);
            list.add(5);
            list.add(2);
            list.add(1);
            list.add(3);

            list.print();
            list.pivoting(3);
            list.print();
        } break;
        case 13: { // Add list based integers
            ll::LinkedList<int> num1;
            num1.add(3);
            num1.add(1);
            num1.add(4);
            ll::LinkedList<int> num2;
            num2.add(7);
            num2.add(0);
            num2.add(9);

            num1.print();
            num2.print();
            ll::LinkedList<int> result = addListBasedIntegers(num1, num2);
            result.print();
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;
    }






    return 0;
}

