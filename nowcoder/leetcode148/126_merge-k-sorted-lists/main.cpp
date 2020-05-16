// date: 2020-05-16
// desc: 合并k个已排序的链表并将其作为一个已排序的链表返回。分析并描述其复杂度。 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // 没有链表
        if (lists.size() == 0)
            return nullptr;
        
        // 将所有链表放入队列
        queue<ListNode*> q;
        for (auto node : lists)
            q.push(node);
        
        // 队列有 2 个以上的链表，就继续合并
        while (q.size() > 1)
        {
            // 取出两个合并 在 加入队列最尾部
            ListNode *list1 = q.front();
            q.pop();
            ListNode *list2 = q.front();
            q.pop();
            q.push(mergeTwoLists(list1, list2));
        }
        
        return q.front();
    }
    
    // 合并两个链表
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 首节点 方便操作
        ListNode *head = new ListNode(0);
        ListNode *tempHead = head;
        
        // 依次处理每个节点，直到其中一个为空
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                 tempHead->next = list1;
                list1 = list1->next;
            }
            else
            {
                tempHead->next = list2;
                list2 = list2->next;
            }
            
            tempHead = tempHead->next;
        }
        
        // 将剩余节点添加到链表末尾
        tempHead->next = (list1 ? list1 : list2);
            
        return head->next;
    }
};

int main(void)
{
    Solution s;
    
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);
    vector<ListNode*> lists {l1, l2, l3};
    
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
    temp = l3;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
    
    l1 = s.mergeKLists(lists);

    temp = l1;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;

    delete l1->next->next->next->next->next->next->next;
    delete l1->next->next->next->next->next->next;
    delete l1->next->next->next->next->next;
    delete l1->next->next->next->next;
    delete l1->next->next->next;
    delete l1->next->next;
    delete l1->next;
    delete l1;

    return 0;
}
