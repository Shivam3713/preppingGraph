class Solution {
    private:
      void dfs(int node, vector<bool>&visited, unordered_map<int, vector<int>>&mp, stack<int>&st){
          visited[node]=true;

          for(int &v:mp[node]){
              if(!visited[v]){
                  dfs(v, visited, mp, st);
              }
          }
          st.push(node);
      }
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          // code here
          unordered_map<int, vector<int>>mp;
          for(int i=0;i<edges.size();i++){
              mp[edges[i][0]].push_back(edges[i][1]);
          }
          vector<bool>visited(V, false);
          stack<int>st;
          for(int i =0;i<V;i++){
              if(!visited[i]){
                  dfs(i, visited, mp, st);
              }
          }
          vector<int>res;
          while(!st.empty()){
              int val = st.top();
              st.pop();
              res.push_back(val);
          }
          return res;
      }
  };