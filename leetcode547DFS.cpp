class Solution {
private:
    void dfs(unordered_map<int, vector<int>>&mp, int node, vector<bool>&visited){
        if(visited[node]) return;
        visited[node] = true;
        for(int &v: mp[node]){
            dfs(mp, v, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>>mp;
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            for(int j =0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n, false);
        int count =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
            dfs(mp, i, visited);
            count++;
            }
        }
        return count;
    }
};