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
        
        int size;
        int listLength = 0;
        ListNode* left = nullptr;
        ListNode* right = nullptr;
        ListNode* currtNode = head;
        // 定义一个头结点
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* tail = nullptr;
        
        // 求出链表长度
        while (currtNode != nullptr)
        {
            listLength++;
            currtNode = currtNode->next;
        }
        
        for (size = 1; size < listLength; size *= 2)
        {
            // 每一次开始的头结点
            currtNode = dummyHead.next;
            tail = &dummyHead;
            
            while (currtNode != nullptr)
            {
                // 链表分三段，第三段下一次处理
                left = currtNode;
                right = cut(currtNode, size);
                currtNode = cut(right, size);
                
                // 合并后的放在新链表的尾部 并将 tail 移动到最后一个结点
                tail->next = merge(left, right);
                while (tail->next != nullptr)
                    tail = tail->next;
            }
        }
    return dummyHead.next;
    }
    
    // 分割链表
    ListNode* cut(ListNode* head, int setp)
    {
        // 要注意将分割开的链表最后一个 next 置为空 所以先走 setp - 1 步
        while (head != nullptr && --setp > 0)
            head = head->next;
        if (head == nullptr)
            return head;
        
        auto temp = head->next;
        head->next = nullptr;
        return temp;
    }
    
    // 合并链表
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummyHead(0);
        ListNode* currNode = &dummyHead;
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                currNode->next = left;
                currNode = left;
                left = left->next;
            }
            else
            {
                currNode->next = right;
                currNode = right;
                right = right->next;
            }
        }
        
        // 将剩余的链表链接到尾部
        if (left == nullptr)
        {
            currNode->next = right;
        }
        else
        {
            currNode->next = left;
        }
        
        return dummyHead.next;
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
