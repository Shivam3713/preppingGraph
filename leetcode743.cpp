class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>mp(n+1);
        for(int i =0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];
            mp[u].push_back({v, time});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>res(n+1, INT_MAX);
        res[k] =0;
        pq.push({0, k}); // {time from source to source, source}
        // int maxi =0;
        while(!pq.empty()){
            int time  = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(res[node]< time) continue;
            for(auto &v: mp[node]){
                int neighbor= v.first;
                int time= v.second;
                if(res[neighbor] > res[node]+time){
                    res[neighbor]= res[node]+time;
                    pq.push({res[node]+time, neighbor});
                }
                
            }
        }
        int maxi=0;
        for(int i=1;i<res.size();i++){
            if(res[i] == INT_MAX){
                return -1;
            }
            maxi = max(maxi, res[i]);
        }
        return maxi;

    }
};