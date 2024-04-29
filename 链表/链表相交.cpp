#include <iostream>
#include "设计链表.cpp"

struct LinkedNode
{
    int val;
    LinkedNode *next;
    LinkedNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    // 寻找末尾相同的链表指针
    LinkedNode *getIntersectionNode(LinkedNode *headA, LinkedNode *headB)
    {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        int diffValue = lengthA >= lengthB ? (lengthA - lengthB) : (lengthB - lengthA);
        LinkedNode *curA = headA;
        LinkedNode *curB = headB;
        if (lengthA >= lengthB)
        {
            while (diffValue--)
            {
                curA = curA->next;
            }
        }
        else
        {
            while (diffValue--)
            {
                curB = curB->next;
            }
        }
        while (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }

    int getLength(LinkedNode *head)
    {
        LinkedNode *cur = head;
        int length = 0;
        while (cur != NULL)
        {
            cur = cur->next;
            length++;
        }
        return length;
    }
};
