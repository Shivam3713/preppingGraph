class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>>mp;
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            mp[u].push_back({cost, v});
        }

        queue<pair<int, int>>q;
        vector<int>result(n,INT_MAX);
        result[src] =0;
        q.push({0, src}); // cost from source to source, source
        

        while(!q.empty() && k>=0){
            int stops = q.size();
            while(stops--){
                pair<int, int>p = q.front();
                int cost = p.first;
                int node = p.second;
                // if(result[node] < cost) continue;
                q.pop();
                for(auto &v: mp[node]){
                    int currCost = v.first;
                    int currNode = v.second;
                    if(cost+currCost < result[currNode]){
                        result[currNode] = cost+currCost;
                        q.push({result[currNode], currNode});
                    }
                }
            }
            --k;
        }
        if(result[dst] != INT_MAX) return result[dst];
        else return -1;
    }
};