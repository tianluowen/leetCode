// date: 2020-04-23
// desc: 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//       将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
//       你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        int length = 0;
        int halflength = 0;
        ListNode* currNode = head;
        ListNode* forntlist = head;
        ListNode* backlist = nullptr;
        
        if (head == nullptr || head->next == nullptr)
            return;
        
        // 链表分为 2 段
        while (currNode != nullptr)
        {
            length++;
            currNode = currNode->next;
        }
        halflength = length / 2;
        if (length % 2 == 1)
            halflength++;
        
        backlist = head;
        for (int i = 0; i < halflength; i++)
        {
            currNode = backlist;
            backlist = backlist->next;
        }
        currNode->next = nullptr;
        
        // 后一半链表反转
        currNode = backlist;
        backlist = backlist->next;
        currNode->next = nullptr;
        ListNode* temp;
        while (backlist != nullptr)
        {
            temp = backlist;
            backlist = backlist->next;
            temp->next = currNode;
            currNode = temp;
        }
        backlist = currNode;
        
        // 定义一个首结点方便操作
        ListNode ListHead(0);
        ListNode* list = &ListHead;
        // 后面的链表挨个插入前面
        int flag = 0;
        while (forntlist != nullptr)
        //while(1)
        {
            if ((flag % 2) == 0)
            {
                list->next = forntlist;
                forntlist = forntlist->next;
            }
            else
            {
                list->next = backlist;
                backlist = backlist->next;
            }
            
            list = list->next;
            flag++;
        }
        if (backlist != nullptr)
            list->next = backlist;
        
        return;
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

    s.reorderList(head);
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
