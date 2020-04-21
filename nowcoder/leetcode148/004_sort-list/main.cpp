// date: 2020-04-21
// desc: 在O(n log n)的时间内使用常数级空间复杂度对链表进行排序。
//       Sort a linked list in O(n log n) time using constant space complexity.

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
