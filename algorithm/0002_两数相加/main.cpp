// date: 2020-03-28
// desc: 两数相加

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        // 相加 l1 l2
        ListNode* l1temp = l1;   
        ListNode* l2temp = l2;
        int sum = 0;
        int mod = 0;
        ListNode* preNodel1 = NULL;
        ListNode* preNodel2 = NULL;

        while(l1temp != NULL && l2temp != NULL)
        {

            sum = l1temp->val + l2temp->val + mod;
            l1temp->val = sum % 10;
            mod = sum / 10;

            preNodel1 = l1temp;      
            preNodel2 = l2temp;      
            l1temp = l1temp->next;
            l2temp = l2temp->next;

        }

        if (l1temp == NULL)
            preNodel1->next = preNodel2->next;

         // 处理进位
         while (mod != 0 && preNodel1->next != NULL)
        {
            sum = preNodel1->next->val + mod;
            mod = sum / 10;
            preNodel1->next->val = sum % 10;
            preNodel1 = preNodel1->next;
        }
        if (mod != 0 && preNodel1->next == NULL)
        {
            preNodel1->next = new ListNode(mod);
        }
    
        return l1;                  
    }
};        


int main(void)
{
    ListNode* l1 = new ListNode(5);
    // ListNode* templ1 = l1;
    // templ1->next = new ListNode(8);

    ListNode* l2 = new ListNode(5);

    Solution s;
    s.addTwoNumbers(l1, l2);

    while (l1 != NULL)
    {
        std::cout << l1->val << "\t";
        l1 = l1->next;
    }
    std::cout << std::endl;

    return 0;
}
