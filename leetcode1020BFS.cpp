class Solution {
vector<int>delrow={-1, 0, 1, 0};
vector<int>delcol={0, 1, 0, -1};
private:
    bool isSafe(int row, int col, vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(row<n && row>=0 && col<m && col >=0 )return true;
        return false;
    }
    void bfs(int row, int col, vector<vector<bool>>&visited, vector<vector<int>>&grid){
        visited[row][col] = true;
        queue<pair<int, int>>q;
        q.push({row, col});
        while(!q.empty()){
            auto p = q.front();
            int row = p.first;
            int col = p.second;
            q.pop();
            for(int i =0;i<4;i++){
                int newR = row+delrow[i];
                int newC = col+delcol[i];
                if(isSafe(newR, newC, grid) && !visited[newR][newC] && grid[newR][newC]==1){
                    q.push({newR, newC});
                    visited[newR][newC]= true;
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        
        //for first and last row;
        for(int i =0;i<m;i++){
            if(!visited[0][i] && grid[0][i] == 1){
                bfs(0, i, visited, grid);
            }
            if(!visited[n-1][i] && grid[n-1][i] == 1){
                bfs(n-1, i, visited, grid);
            }
        }
        for(int i =0;i<n;i++){
            if(!visited[i][0] && grid[i][0] == 1) bfs(i, 0, visited, grid);
            if(!visited[i][m-1] && grid[i][m-1] == 1) bfs(i, m-1, visited, grid);
        }
        int count =0;
        for(int i =0;i<n;i++)for(int j =0;j<m;j++){
            if(!visited[i][j] && grid[i][j]) count++;
        }
        return count;
    }
};