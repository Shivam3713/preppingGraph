class Solution {
private:
    bool dfs(unordered_map<int, vector<int>>&mp, int u, vector<bool>& visited, int parent){
        visited[u]= true;
        for(int &v: mp[u]){
            if(v== parent) continue;
            if(visited[v]) return true;
            if(dfs(mp, v, visited, u)) return true;

        }
        return false;

    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>>mp;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(V, false);
        for(int i =0;i<V;i++){
            if(!visited[i] && dfs(mp, i, visited, -1)){
                return true;
            }
        }
        return false;

    }
};