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
    Node* cloneGraph(Node* node) { 
        hash.clear();
        if(node == NULL) return NULL;
        queue<Node*> que;
        que.push(node);
        while(!que.empty()) {
            Node* curr = que.front();
            que.pop();
            Node* newNode;
            if(hash[curr->val] == NULL) {
                newNode = new Node(curr->val);
                hash[curr->val] = newNode;
            } else {
                newNode = hash[curr->val];
            }
            for(Node* neigh: curr->neighbors) {
                if(hash[neigh->val])
                    newNode->neighbors.push_back(hash[neigh->val]);
                else {
                    Node* ne = new Node(neigh->val);
                    newNode->neighbors.push_back(ne);
                    hash[ne->val] = ne;
                    que.push(neigh);
                }
            }
        }
        return hash[1];
    }
};
