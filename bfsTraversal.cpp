class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                mp[i].push_back(adj[i][j]);
            }
        }

        queue<int>q;
        vector<int>visited(adj.size(), false);
        vector<int>res;
        q.push(0);
        res.push_back(0);
        while(!q.empty()){
            int node = q.front();
            q.ppo();
            visited[node]= true;
            for(int &v: mp[node]){
                if(!visited[v]){
                    visited[v]= true;
                    res.push_back(v);
                    q.push(v);  
                }
            }
        }
        return res;
        
        
    }
};