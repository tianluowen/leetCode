// date: 2020-05-15
// desc: 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 定义一个空的头节点，方便使用
        ListNode *head = new ListNode(0);
        ListNode *temp = head;

        // 当 l1 l2 都为空时，结束
        while (l1 != nullptr || l2 != nullptr)
        {
            // l1 为空 赋值 l2
            if (l1 == nullptr)
            {
                head->next = l2;
                head = head->next;
                l2 = l2->next;
            }
            // l2 为空 赋值 l1
            else if (l2 == nullptr)
            {
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            }
            else
            {
                // 都不为空 谁小赋值谁
                if (l1->val <= l2->val)
                {
                    head->next = l1;
                    head = head->next;
                    l1 = l1->next;
                }
                else
                {
                    head->next = l2;
                    head = head->next;
                    l2 = l2->next;
                }
            }   
        }

        // 返回真正的头
        return temp->next;
    }
};

int main(void)
{
    Solution s;
    
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    ListNode *temp = l1;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
   temp = l2;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
    
    l1 = s.mergeTwoLists(l1, l2);

    temp = l1;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;

    delete l1->next->next->next->next->next;
    delete l1->next->next->next->next;
    delete l1->next->next->next;
    delete l1->next->next;
    delete l1->next;
    delete l1;

    return 0;
}
