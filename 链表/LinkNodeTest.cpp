#include <iostream>
#include "设计链表.cpp"

int main()
{
    MyLinkedList linkList;
    linkList.addAtHead(1);
    linkList.addAtHead(2);
    linkList.addAtHead(3);
    linkList.addAttail(10);
    linkList.addAttail(30);
    linkList.addAtHead(5);
    // int val = linkList.get(3); // 获取第index为3的值
    // std::cout << val << std::endl;
    linkList.printLinkList();
    // linkList.reverseList();
    linkList.reverseListRec();
    linkList.printLinkList();
    return 0;
}