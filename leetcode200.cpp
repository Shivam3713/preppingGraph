class Solution {
int delrow[4] = {1, 0, -1, 0};
int delcol[4] = {0, 1, 0, -1};
private:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>&grid){
        if(visited[row][col]) return;
        queue<pair<int, int>>q;
        q.push({row, col});
        visited[row][col]= 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            for(int i=0;i<4;i++){
                int newR = row+delrow[i];
                int newC = col+delcol[i];
                if(newR < grid.size() && newR >=0 && newC <grid[0].size() && newC >=0 && !visited[newR][newC] && grid[newR][newC] == '1'){
                    visited[newR][newC]=1;
                    q.push({newR, newC});
                }
                
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i, j, visited, grid);
                    count++;
                }
            }
        }
        return count;

    }
};