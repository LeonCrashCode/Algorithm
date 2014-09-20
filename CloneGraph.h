#ifndef CloneGraph_H
#define CloneGraph_H

#include "common.h"
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        queue<const UndirectedGraphNode *> q;
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copy;
        q.push(node);
        copy[node] = new UndirectedGraphNode(node->label);
        while(q.empty()==false)
        {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for(int i = 0; i < cur->neighbors.size(); i ++)
            {
                const UndirectedGraphNode *p = cur->neighbors[i];
                if(copy.find(p) != copy.end())
                {
                    copy[cur]->neighbors.push_back(copy[p]);
                }
                else
                {
                    UndirectedGraphNode *nbn = new UndirectedGraphNode(p->label);
                    copy[p] = nbn;
                    copy[cur]->neighbors.push_back(nbn);
                    q.push(p);
                }
            }
        }
        return copy[node];
    }
};

#endif