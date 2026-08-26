class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>>mp;
        for(int i =0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
        }

        //create indegree vectir;
        vector<int>indegree(V, 0);
        for(auto &it : mp){
            for(int &v: it.second){
                indegree[v]++;
            }
        }
        queue<int>q;
        //push everyone in queue whoever has indegree 0;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)q.push(i);
        }

        vector<int>res;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(int &v: mp[curr]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return res;

    }
};