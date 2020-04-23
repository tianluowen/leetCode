// date: 2020-04-23
// desc: 对于一个给定的链表，返回环的入口节点，如果没有环，返回null 

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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        int flag = 0;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag == 1)
        {
            while (head != slow)
            {
                head = head->next;
                slow = slow->next;
            }
            return head;
        }
        
        return nullptr;
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
    head->next->next->next->next->next = head->next;


    cout << "原来的链表是: " << endl << "[ 2 ][ 4 ][ 3 ][ 1 ][ 6 ]" << endl;
    cout << "6 后面接 4" << endl;

    tempNode = s.detectCycle(head);

    cout << "结点处的数据为:  " << tempNode->val << endl;

    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head;

    return 0;
}
