// date: 2020-05-15
// desc: 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 返回原链表
        if (n == 0)
            return head;
        
        ListNode* pNode = head;
        ListNode* pcurrtNode = head;
        while (n > 0 && pNode != nullptr)
        {
            pNode = pNode->next;
            n--;
        }

        // 这种情况删除的是第一个节点
        if (n == 0 && pNode == nullptr)
        {
            return head->next;
        }
        else  // 删除的非第一个节点
        {
            // 找到该节点的前一个节点
            while (pNode->next != nullptr)
            {
                pNode = pNode->next;
                pcurrtNode = pcurrtNode->next;
            }
            // 删除该节点   
            pcurrtNode->next = pcurrtNode->next->next;

            return head;
        }   
    }
};

int main(void)
{
    Solution s;
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << "\tn = 2" << endl;
    
    head = s.removeNthFromEnd(head, 2);

    temp = head;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
