class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>mp;
        for(int i =0;i<edges.size();i++){
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool>visited(numCourses, false);
        vector<int>indegree(numCourses);
        for(auto &it: mp){
            for(int &v: it.second) indegree[v]++;
            
        }
        int count =0;
        queue<int>q;
        for(int i=0;i<numCourses;i++)if(indegree[i] == 0)q.push(i);
        vector<int>res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            res.push_back(node);
            for(int &v: mp[node]){
                indegree[v]--;
                if(indegree[v] == 0)q.push(v);
            }
        }
        if(count == numCourses) return res;
        else return {};

    }
};