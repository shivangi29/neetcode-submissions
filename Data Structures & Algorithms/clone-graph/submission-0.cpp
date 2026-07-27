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
    unordered_map<int, Node*> hash;
    Node* dfs(Node* node) {
        if(node == NULL) return NULL;
        Node* newNode = new Node(node->val);
        hash[node->val] = newNode;
        vector<Node*> tmp = node->neighbors;
        for(int i = 0 ; i < tmp.size();i++) {
            Node* neigh = node->neighbors[i];
            if(hash[neigh->val] == NULL)
                newNode->neighbors.push_back(dfs(neigh));
            else
                newNode->neighbors.push_back(hash[neigh->val]);
        }
        return newNode;
        
    }
    Node* cloneGraph(Node* node) { 
        hash.clear();
        return dfs(node);
    }
};
