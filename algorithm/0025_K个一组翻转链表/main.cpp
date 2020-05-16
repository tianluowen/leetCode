// date: 2020-05-16
// desc: 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//       k 是一个正整数，它的值小于或等于链表的长度。
//       如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 传入链表为空 return 空
        if (head == nullptr)
            return nullptr;

        // 定义变量
        ListNode* returnHead = new ListNode(0);
        ListNode* tempReturnHead = returnHead;
        ListNode* beginNode = head;
        int countNode = 0;

        // 处理链表
        while (head != nullptr)
        {
            countNode++;
            
            // 找到前 k 个接节点
            if (countNode == k)
            {
                // 计数置 0 分割链表
                countNode = 0;
                ListNode* endNode = head;
                head = head->next;
                endNode->next = nullptr;

                // 翻转链表
                tempReturnHead->next = reverseList(beginNode);
                beginNode = head;

                // 移动 tempReturnHead 到最后一个节点
                while (tempReturnHead->next != nullptr)
                {
                    tempReturnHead = tempReturnHead->next;
                }
            }
            else
            {
                head = head->next;
            }
        }

        // 处理链表后面 小于 k 的部分
        if (countNode == 0)
            tempReturnHead->next = nullptr;
        else
            tempReturnHead->next = beginNode;
        
        // 返回
        return returnHead->next;
    }

    // 翻转一个链表
    ListNode* reverseList(ListNode* head)
    {
        // 空链表
        if (head == nullptr)
            return nullptr;
        
        // 第一个节点
        ListNode* returnNode = head;
        head = head->next;
        returnNode->next = nullptr;
        
        // 其余的节点
        ListNode* tempNode;
        while (head != nullptr)
        {
            tempNode = head;
            head = head->next;
            tempNode->next = returnNode;
            returnNode = tempNode;
        }

        // 返回
        return returnNode;
    }
};

int main(void)
{
    Solution s;
    
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    
    ListNode *temp = l1;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << " k = 3" << endl;
    
    l1 = s.reverseKGroup(l1, 3);

    temp = l1;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;

    delete l1->next->next->next->next;
    delete l1->next->next->next;
    delete l1->next->next;
    delete l1->next;
    delete l1;

    return 0;
}
