#include <iostream>
#include "设计链表.cpp"

void test()
{
    MyLinkedList linkListA;
    linkListA.addAtHead(1);
    linkListA.addAtHead(2);
    linkListA.addAtHead(3);
    linkListA.addAttail(10);
    linkListA.addAttail(30);
    linkListA.addAtHead(5);
    linkListA.addAtHead(6);
    // int val = linkListA.get(3); // 获取第index为3的值
    // std::cout << val << std::endl;
    linkListA.printLinkList();

    MyLinkedList linkListB;
    linkListB.addAtHead(3);
    linkListB.addAtHead(5);
    linkListB.addAtHead(6);
    linkListB.addAttail(10);
    linkListB.addAttail(30);
    linkListB.addAtHead(5);
    linkListB.addAtHead(6);

    linkListB.printLinkList();

    int result = linkListA.getIntersectionNode(linkListA, linkListB);
    std::cout << result << std::endl;
}

void test01()
{
    MyLinkedList linkList;
    linkList.addAtHead(1);
    linkList.addAtHead(2);
    linkList.addAtHead(3);
    linkList.addAttail(10);
    linkList.addAttail(30);
    linkList.addAtHead(5);
    linkList.addAtHead(6);
    // int val = linkList.get(3); // 获取第index为3的值
    // std::cout << val << std::endl;
    linkList.printLinkList();
    // linkList.reverseList();
    // linkList.reverseListRec();
    // linkList.swapPair();
    linkList.removeLastEle2(1);
    linkList.printLinkList();
}

int main()
{
    test();
    return 0;
}