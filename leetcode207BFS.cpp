class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>mp;
        vector<bool>visisted(edges.size(), false);
        queue<int>q;
        vector<int>indegree(numCourses, 0);
        for(int i =0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
        }

        for( auto it: mp){
            for(int &v: it.second){
                indegree[v]++;
            }
        }

        for(int i =0;i<indegree.size();i++) if(indegree[i]  == 0) q.push(i);
        int count =0;
        vector<int>res;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            count++;
            res.push_back(node);
            for(int &v: mp[node]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        if(numCourses == count) return true;
        else return false;
    }
};