typedef pair<long long, int> P;
const int M = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>>mp;

        for(int i =0;i<roads.size();i++){
            mp[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            mp[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<int>count(n, 0);
        vector<long long>distance(n, LLONG_MAX);
        int source =0;
        count[source] =1;
        distance[source]=0;
        
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, 0}); //time to reach node  {time, node}
        while(!pq.empty()){
            long long time  = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(time > distance[node]) continue;
            for(auto &v: mp[node]){
                int currNgbr = v.first;
                long long currTime = v.second;
                if(distance[currNgbr] > time+currTime){
                    distance[currNgbr] = time+currTime;
                    pq.push({distance[currNgbr], currNgbr});
                    count[currNgbr] = count[node]%M;
                }
                else if(distance[currNgbr] == currTime+time){
                    count[currNgbr] = (count[currNgbr]+count[node])%M;
                }
            }
        }
        return count[n-1];

    }
};