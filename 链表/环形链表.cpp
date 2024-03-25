#include <iostream>
#include "ListNode.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                // 从该节点重新出发计算相遇的节点，便为起始结点
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};