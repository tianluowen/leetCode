// date: 2020-04-29
// desc: 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）
//       图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for undirected graph.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}; 

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> nodemap;
        queue<Node*> q;
        Node* tempNode = nullptr;
        Node* newNode = nullptr;
        
        q.push(node);
        while (!q.empty())
        {
            // 取出元素
            tempNode = q.front();
            q.pop();
            
            // 分配空间
            newNode = new Node(tempNode->val);
            nodemap.insert({tempNode, newNode});

            // 这个元素不在 map 中，分配内存，添加到 map 中
            for (Node* ite : tempNode->neighbors)
            {
                if (nodemap.find(ite) == nodemap.end())
                {
                    q.push(ite);
                }
            }
        }
        
        // 处理关系
        unordered_map<Node*, Node*>::iterator iter;
        for (iter = nodemap.begin(); iter != nodemap.end(); iter++)
        {
            for (Node* ite: iter->first->neighbors)
            {
                iter->second->neighbors.push_back(nodemap.find(ite)->second);
            }
        }
        
        return nodemap.find(node)->second;
    }
};
        
int main(void)
{
    Solution s;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(node4);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node3);
    node4->neighbors.push_back(node1);

    Node* resultNode = s.cloneGraph(node1);

    cout << "resultNode1 = " << resultNode->val << endl;
    cout << "resultNode2 = " << (resultNode->neighbors)[1]->val << endl;
    cout << "resultNode3 = " << (resultNode->neighbors)[1]->neighbors[1]->val << endl;
    cout << "resultNode4 = " << (resultNode->neighbors)[0]->val << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete (*(resultNode->neighbors)[1]).neighbors[1];
    delete (resultNode->neighbors)[0];
    delete (resultNode->neighbors)[1];
    delete resultNode;

    return 0;
}
