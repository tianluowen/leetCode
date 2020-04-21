// date: 2020-04-21
// desc: 对链表进行插入排序。

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        // 0 个 或者 1 个结点，直接返回该结点
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        // 遍历每一个结点，插入到前面的新链表中
        ListNode* currtNode = head;
        ListNode* headNode = nullptr;
        ListNode* tempNode = nullptr;
        while (currtNode != nullptr)
        {
            tempNode = currtNode->next;
            headNode = insert(headNode, currtNode);
            
            currtNode = tempNode;
        }
        
        return headNode;
    }
    ListNode* insert(ListNode* head, ListNode* processNode)
    {
        if (head == nullptr)
        {
            processNode->next = nullptr;
            return processNode;
        }
        
        // 头插入
        if (processNode->val <= head->val)
        {
            processNode->next = head;
            return processNode;
        }
        
        ListNode* proNode = head;
        ListNode* currtNode = head->next;
        
        while (currtNode != nullptr)
        {
            // 中间插入
            if (processNode->val > currtNode->val)
            {
                proNode = currtNode;
                currtNode = currtNode->next;
            }
            else
            {
                processNode->next = currtNode;
                proNode->next = processNode;
                return head;
            }
        }
        
        // 尾插
        proNode->next = processNode;
        processNode->next = nullptr;
        return head;
    }
};




int main(void)
{
    Solution s;
    
    ListNode* head = new ListNode(2);
    ListNode* tempNode = nullptr;
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(6);

    cout << "原来的链表是: " << endl << "[ 2 ][ 4 ][ 3 ][ 1 ][ 6 ]" << endl;

    head = s.sortList(head);
    tempNode = head;

    while (tempNode != nullptr)
    {
        cout << "[ " << tempNode->val << " ]";
        tempNode = tempNode->next;
    }
    cout << endl;

    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head;

    return 0;
}
