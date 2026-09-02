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
    void bfs(Node* node, Node* clone, unordered_map<Node*, Node*>&mp){
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* node  = q.front();
            Node* clone = mp[node];
            q.pop();
            for(Node* n:node->neighbors){
                if(mp.find(n) == mp.end()){
                    Node* cloned = new Node(n->val);
                    mp[n] = cloned;
                    clone->neighbors.push_back(cloned);
                    q.push(n);
                }
                else{
                    clone->neighbors.push_back(mp[n]);
                }
            }

        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* clone = new Node(node->val);
        unordered_map<Node*, Node*>mp;
        mp[node] = clone;
        bfs(node, clone, mp);
        return clone;
    }
};