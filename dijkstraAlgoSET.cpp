class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int, vector<pair<int, int>>>mp;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }
        set<pair<int, int>>st;
        vector<int>distance(V, INT_MAX);
        distance[src] =0;
        st.insert({0, src});
        while(!st.empty()){
            auto p = st.begin();
            int node = p->second;
            int wt = p->first;
            st.erase({wt, node});
            for(pair<int, int> &v: mp[node]){
                int visitingNode = v.first;
                int edgeWt = v.second;
                if(distance[visitingNode] > distance[node] + edgeWt){
                    st.erase({distance[visitingNode], visitingNode});
                    distance[visitingNode] = distance[node] + edgeWt;
                    st.insert({distance[node]+edgeWt, visitingNode});
                }
            }

        }
        return distance;
    }
};