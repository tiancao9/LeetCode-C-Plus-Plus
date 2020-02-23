/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        if(node == NULL)
            return NULL;
        q.push(node); 
        UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
        m[node] = head;
        while(!q.empty())
        {
            UndirectedGraphNode* cur = q.front(); q.pop();
            UndirectedGraphNode* copied = m[cur];
            for(int i = 0; i < cur->neighbors.size(); i++)
            {
                if(!m.count(cur->neighbors[i]))
                {
                    UndirectedGraphNode* new_n = new UndirectedGraphNode(cur->neighbors[i]->label);
                    m[cur->neighbors[i]] = new_n;
                    q.push(cur->neighbors[i]);
                }
                copied->neighbors.push_back(m[cur->neighbors[i]]);
            }
        }
        
        return m[node];
        
    }
};

// New Node class defination.
/*
// Definition for a Node.
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
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
      if (!node) return NULL;
      unordered_map<Node*, Node*> m;
      queue<Node*> q;
      q.push(node);
      m[node] = new Node(node->val);
      while (!q.empty()) {
          Node* cur = q.front(); q.pop();
          for (auto neighbor : cur->neighbors) {
              if (!m.count(neighbor)) {
                  m[neighbor] = new Node(neighbor->val);
                  q.push(neighbor);
              }
              m[cur]->neighbors.push_back(m[neighbor]);              
          }
      }
      return m[node];
    }
};
