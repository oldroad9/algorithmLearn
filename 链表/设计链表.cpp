#include <iostream>
// #include "ListNode.h"

class MyLinkedList
{
public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int x) : val(x), next(NULL) {}
    };

    // 初始化链表
    MyLinkedList() // 构造函数
    {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index > _size - 1)
        {
            return -1;
        }
        LinkedNode *curr = _dummyHead->next;
        while (index--) // 如果--index 就会陷入死循环 从第0个开始判断
        {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int value)
    {
        LinkedNode *newNode = new LinkedNode(value);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++; //  大小要加1
    }

    void addAttail(int value)
    {
        LinkedNode *newNode = new LinkedNode(value);
        LinkedNode *cur = _dummyHead;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int value)
    {
        if (index < 0)
        {
            return;
        }
        if (index > _size)
        {
            addAttail(value);
        }
        LinkedNode *newNode = new LinkedNode(value);
        LinkedNode *cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index) // 删除index索引的元素
    {
        if (index < 0 || index > _size || _size == 0)
        {
            return;
        }
        LinkedNode *cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    void printLinkList()
    {
        if (_size == 0)
        {
            return;
        }
        LinkedNode *cur = _dummyHead;
        while (cur->next != NULL)
        {
            std::cout << cur->next->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
    // 实现链表反转
    void reverseList() // 双指针法
    {
        LinkedNode *tmp;
        LinkedNode *cur = _dummyHead->next->next;
        LinkedNode *pre = _dummyHead->next;
        pre->next = NULL;
        while (cur->next != NULL)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        cur->next = pre;
        _dummyHead->next = cur;
    }
    void reverseListRec() // 递归的方法
    {
        _dummyHead->next = reverse(NULL, _dummyHead->next);
    }
    LinkedNode *reverse(LinkedNode *pre, LinkedNode *cur)
    {
        // 不断循环反转两个值
        if (cur == NULL)
            return pre;
        LinkedNode *tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }

    // 实现两两交换
    void swapPair()
    {
        LinkedNode *cur = _dummyHead;
        LinkedNode *rear = cur->next;
        //  判断放在前面
        while ((cur->next != NULL) && (rear->next != NULL))
        {
            LinkedNode *tmp = rear;
            LinkedNode *tmp1 = rear->next->next;
            // 进行三步交换
            cur->next = rear->next;
            rear->next->next = tmp;
            rear->next = tmp1;
            // 要移动两位
            cur = cur->next->next;
            rear = cur->next;
        }
    }
    //  删除链表的倒数第几个元素
    void removeLastEle(int index)
    {
        LinkedNode *fast = _dummyHead->next;
        LinkedNode *slow = _dummyHead->next;
        while (fast->next != NULL)
        {
            // 理清逻辑 避免不进入
            if (index == 0)
            {
                slow = slow->next;
            }
            if (index != 0)
                index--;
            fast = fast->next;
        }
        LinkedNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        _size--;
    }

    void removeLastEle2(int index)
    {
        LinkedNode *fast = _dummyHead->next;
        LinkedNode *slow = _dummyHead->next;
        // 让fast先走几步
        while (index-- && fast != NULL)
        {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        LinkedNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        _size--;
    }

    LinkedNode *getHead()
        const
    {
        return _dummyHead;
    }

    int getIntersectionNode(MyLinkedList &linkListA, MyLinkedList &linkListB)
    {
        LinkedNode *headA = linkListA.getHead()->next;
        LinkedNode *headB = linkListB.getHead()->next;
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
        return curA->val;
    }

    // 判断链表长度
    int getLength(LinkedNode *head)
    {
        LinkedNode *cur = head;
        int length = 0;
        while (cur != NULL)
        {
            cur = cur->next;
            length++;
        }
        std::cout << length << std::endl;
        return length;
    }

private:
    int _size;
    LinkedNode *_dummyHead;
};