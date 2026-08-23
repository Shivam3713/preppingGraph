class Solution {
private:
void bfs(unordered_map<int, vector<int>>mp, int node, vector<bool>&visited){
    if(visited[node]) return ;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        visited[curr]= true;
        for(int &v: mp[curr]){
            if(!visited[v]){
                visited[v]= true;
                q.push(v);
            }
        }
    }
    

}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>>mp;
        int n = isConnected.size();
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            if(isConnected[i][j]){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
        vector<bool>visited(n, false);
        int count =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(mp, i, visited);
                count++;
            }
        }
        return count;
    }
};