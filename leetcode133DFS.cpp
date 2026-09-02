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
private:
    void dfs(Node* node, Node* clone, unordered_map<Node*, Node*>&mp){
        //two cases, no node present then crete and put it in map and call dfs for that
        //else store the node if already there
        for(Node* n: node->neighbors){
            if(mp.find(n) == mp.end()){
                Node* cloned = new Node(n->val);
                mp[n] = cloned;
                clone->neighbors.push_back(cloned);
                dfs(n, cloned, mp);
            }
            else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node *clone = new Node(node->val);
        unordered_map<Node*, Node*>mp;
        mp[node] = clone;
        dfs(node, clone, mp);
        return clone;
    }
};