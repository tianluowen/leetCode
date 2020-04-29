// date: 2020-04-29
// desc: 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
        
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodemap;
        queue<UndirectedGraphNode*> q;
        UndirectedGraphNode* tempNode = nullptr;
        UndirectedGraphNode* newNode = nullptr;
        
        q.push(node);
        while (!q.empty())
        {
            // 取出元素
            tempNode = q.front();
            q.pop();
            
            // 分配空间
            newNode = new UndirectedGraphNode(tempNode->label);
            nodemap.insert({tempNode, newNode});

            // 这个元素不在 map 中，分配内存，添加到 map 中
            for (UndirectedGraphNode* ite : tempNode->neighbors)
            {
                if (nodemap.find(ite) == nodemap.end())
                {
                    q.push(ite);
                }
            }
        }
        
        // 处理关系
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator iter;
        for (iter = nodemap.begin(); iter != nodemap.end(); iter++)
        {
            for (UndirectedGraphNode* ite: iter->first->neighbors)
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
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
    UndirectedGraphNode* node3 = new UndirectedGraphNode(3);
    UndirectedGraphNode* node4 = new UndirectedGraphNode(4);
    node1->neighbors.push_back(node4);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node3);
    node4->neighbors.push_back(node1);

    UndirectedGraphNode* resultNode = s.cloneGraph(node1);

    cout << "resultNode1 = " << resultNode->label << endl;
    cout << "resultNode2 = " << (resultNode->neighbors)[1]->label << endl;
    cout << "resultNode3 = " << (resultNode->neighbors)[1]->neighbors[1]->label << endl;
    cout << "resultNode4 = " << (resultNode->neighbors)[0]->label << endl;

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
