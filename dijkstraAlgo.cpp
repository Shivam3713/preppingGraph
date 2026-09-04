class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        unordered_map<int, vector<pair<int, int>>>mp;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }
        
        vector<int>res(V, INT_MAX);
        
        res[src] =0;
        pq.push({0, src}); //{pehele weight, fir node} in dj algo we usually do like this
        while(!pq.empty()){
            
            // int wt = pq.first;
            // int node = pq.second;
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(distance > res[node]) continue;
            for(auto &v: mp[node]){
                int neighbor = v.first;
                int wt = v.second;
                if(res[neighbor] > res[node]+wt){
                    res[neighbor] = res[node]+wt;
                    pq.push({res[neighbor], neighbor});
                }
            }
        }
        return res;
        
        
    }
};