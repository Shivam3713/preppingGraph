class Solution {    
private:
    bool bfs(int node, vector<vector<int>>&graph, vector<int>&colored, int currColor){
        queue<int>q;
        q.push(node);
        colored[node]= currColor;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(int &v : graph[currNode]){
                if(colored[v] == -1){
                    colored[v] = 1-colored[currNode];
                    q.push(v);
                }
                if(colored[v] == colored[currNode]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>colored(graph.size(), -1); //initially none are colored;

        for(int i=0;i<graph.size();i++){
            if(colored[i] == -1){
                if(!bfs(i, graph, colored, 1)) return false;
            }
        }
        return true;
    }
};