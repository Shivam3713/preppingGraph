class Solution {
  private:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>>&mp, vector<bool>&visited, stack<int>&st){
      visited[node]=true;
      for(auto &v: mp[node]){
        if(!visited[v.first]){
          dfs(v.first, mp, visited, st);
        }
      }
      st.push(node);
    }
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>>mp;
        int n = edges.size();
        for(int i=0;i<n;i++){
          int u = edges[i][0];
          int v = edges[i][1];
          int wt = edges[i][2];
          mp[u].push_back({v, wt});
        }

        // vector<int>topo(mp.size(),0);
        vector<bool>visited(V, false);
        stack<int>st;
        for(int i =0;i<V;i++){
          if(!visited[i]){
            dfs(i, mp, visited, st);
          }
        }

        //now after this our topo vector is initialized with values
        vector<int>distance(V, INT_MAX);
        distance[0] =0;
        while(!st.empty()){
          int node = st.top();
          st.pop();
          for(auto &v: mp[node]){
            int neighbor = v.first;
            int wt = v.second;
            if(distance[node] == INT_MAX) continue; //ye isliye check karne kie liye hai ki agar hum kisi aise node pe hai jo abhi tak dscover hi nahi hua toh needhe INT_MAX+wt hojayeg ajoki galat hai
            if(distance[neighbor] > distance[node]+wt){
              distance[neighbor] = distance[node]+wt;
            }
          }
        }
        for(int i=0;i<distance.size();i++){
          if(distance[i] == INT_MAX){
            distance[i] = -1;
          }
        }
        return distance;


    }
};
