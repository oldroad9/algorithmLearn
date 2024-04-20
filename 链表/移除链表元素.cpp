#include <iostream>
#include "ListNode.h"

// 删除链表中等于给定值 val 的所有节点。

class Solution
{
public:
    static ListNode *removeElements(ListNode *head, int val)
    {
        // 删除头结点 删除所有值相同的val
        while (head != NULL && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除非头结点
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }

    static ListNode *removeElements2(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head;                // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode *cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
