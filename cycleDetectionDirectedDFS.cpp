class Solution {
  private:
    bool dfs(int node, unordered_map<int, vector<int>>&edges, vector<bool>&visited,vector<bool>&inRecursion){
        visited[node]= true;
        inRecursion[node]=true;
        for(int &v: edges[node]){
            if(visited[v] && inRecursion[v]) return true;
            else if(!visited[v]){
                if(dfs(v, edges, visited, inRecursion)) return true;
            }
        } 
        inRecursion[node]= false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<edges.size();i++)for(int j=0;j<edges[0].size();j++){
            mp[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool>inRecursion(V, false);  
        vector<bool>visited(V, false);
        for(int i =0;i<V;i++){
           if( !visited[i] && dfs(i, mp, visited, inRecursion)) return true;
            
        }
        return false;
        
    }
};
