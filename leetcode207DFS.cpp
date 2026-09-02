class Solution {
private:
    bool dfs(int node, unordered_map<int, vector<int>>&mp, vector<bool>&visited, vector<bool>&inRecursion){
        visited[node]= true;
        inRecursion[node]=true;
        for(int &v: mp[node]){
            if(visited[v] && inRecursion[v]) return true;
            if(!visited[v]){
                if(dfs(v, mp, visited, inRecursion)){
                    return true;
                }
            }
        }
        inRecursion[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>mp;
        for(int i =0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool>visited(numCourses, false);
        vector<bool>inRecursion(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(i, mp, visited, inRecursion) == true) return false;
        }
        return true;
    }
};