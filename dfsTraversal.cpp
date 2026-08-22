class Solution {
    private:
    void dfsTraversal(unordered_map<int, vector<int>>&mp, int node, vector<bool>&visited, vector<int>&res){
        if(visited[node]) return; //if node is already visited just return the node
        visited[node] = true;
        res.push_back(node);

        for(int &v: mp[node]){
            if(!visited[v]){
                dfsTraversal(mp, v, visited, res);

            } //if the node im going to from current is not visited then do this
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        //first let's put the adj matrix into unordered_map
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                mp[i].push_back(adj[i][j]);
            }
        }
        vector<int>res;
        vector<bool>visited(adj.size(), false);
        dfsTraversal(mp, 0, visited, res);
        return res;

    }
};