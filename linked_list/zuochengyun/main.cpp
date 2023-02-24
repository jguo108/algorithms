#include "list.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 1: { // 反转单向和双向列表
          LinkedList ll({1,2,3,4,5,6,7,8,9,10});
          ll.print();
          ll.reverse();
          ll.print();
        } break;
        case 2: { // 反转部分单向列表 TODO: worked but ugly.
          LinkedList ll({1,2,3,4,5,6,7,8,9,10});
          ll.print();
          ll.reverse_from_to(4,10);
          ll.print();
        } break;
        case 3: { // 判断一个链表是否为回文结构 
          LinkedList ll({1,2,3,4,5,6,7,8,9,10});
          ll.is_plindrome();
        } break;
        case 4: { // 将单链表的每K个节点之间逆序
          LinkedList ll({1,2,3,4,5,6,7,8});
          ll.print();
          ll.reverse(4);
          ll.print();
        } break;
        case 5: { // 单链表的选择排序 
          LinkedList ll({5,4,9,1,3,7,10,0,2,8,6});
          ll.print();
          ll.selection_sort();
          ll.print();
        } break;
        case 6: { // 向有序的环形单链表中插入新节点
          LinkedList ll({1,5,10,15,20,25,30,35,40,45});
          ll.make_circle();
          ll.print(ll.size());
          ll.insert_into_sorted(22);
          ll.print(ll.size());
        } break;
        case 7: { // 按照左右半区的方式重新组合单链表
          LinkedList ll({1,2,3,4,5,6,7,8,9});
          ll.print();
          ll.left_right_merge();
          ll.print();
        } break;
    }
    return 0;
}