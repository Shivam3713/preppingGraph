const int INF = 100000000;
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>res(V, INF);
        res[src] = 0;
        for(int i=1;i<=V-1;i++){
            for(auto & edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if( res[u] != INF && res[v] > res[u]+wt){
                    res[v] = res[u]+wt;
                }
            }
        }
        for(auto & edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(res[u] != INF && res[v] > res[u]+wt) return {-1};
        }
        return res;
        
    }
};
