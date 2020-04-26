// date: 2020-04-26
// desc: 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//       要求返回这个链表的 深拷贝。 

#include <iostream>

using namespace std;
        
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
            if (head == nullptr)
        return nullptr;

        // copyt 链表 val next
        Node* copyhead = new Node(head->val);
        Node* currtNode = head->next;
        Node* currtcopy = copyhead;
        while (currtNode != nullptr)
        {
            currtcopy->next = new Node(currtNode->val);
            currtcopy = currtcopy->next;
            currtNode = currtNode->next;
        }

        // copy random
        currtNode = head;
        currtcopy = copyhead;
        int index;
        while(currtNode)
        {
            // 找到在原来结点的位置
            if (currtNode->random != nullptr)
            {
                index = pos(head, currtNode->random);

                // 找到 copy 结点的地址
                Node* temp = copyhead;
                while (index--)
                {
                    temp = temp->next;
                }
                currtcopy->random = temp;
            }

            // 位置变换
            currtNode = currtNode->next;
            currtcopy = currtcopy->next;
        }
        return copyhead;
    }

    // 找到老链表中随机结点的位置
    int pos(Node *head, Node *node)
    {
        int index = 0;
        while(node != head)
        {
            head = head->next;
            index++;
        }

        return index;
    }
};

int main(void)
{
    Solution s;

    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head;

    cout << "head = [[7,null],[13,0],[11,4],[10,2],[1,0]]" << endl;
    Node* result = s.copyRandomList(head);

    cout << "为了简单输出，第二个值代表随机结点的数据" << endl;
    cout << "[ ";
    while (result != nullptr)
    {
        if (result->random == nullptr)
            cout << "[" << result->val << ", null]";
        else
            cout << "[" << result->val << ", " << result->random->val << "]";

        result = result->next;
    }
    cout << " ]" << endl;

    return 0;
}
