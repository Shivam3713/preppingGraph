class Solution {
  private:
    bool isCycleBFS(int source, int parent, unordered_map<int, vector<int>>&mp, vector<bool>&visited){
        queue<pair<int, int>>q;
        q.push({source, parent});
        visited[source]= true;
        while(!q.empty()){
            pair<int, int>p = q.front();
            q.pop();
            int source = p.first;
            int parent = p.second;
            for(int &v: mp[source]){
                if(!visited[v]){
                    visited[v]= true;
                    q.push({v, source});
                  }
                 else if(visited[v] && v!=parent) return true;
              }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>>mp;
        for(auto &edge : edges){
            int u= edge[0];
            int v= edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool>visited(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleBFS(i, -1, mp, visited)){
                return true;
            }
        }
        return false;


    }
};