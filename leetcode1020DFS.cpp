class Solution {
vector<int>delrow ={-1, 0, 1, 0};
vector<int>delcol = {0, 1, 0, -1};
private:
    bool isSafe(int row, int col, vector<vector<int>>&grid){
        int n= grid.size();
        int m =grid[0].size();
        if(row < n && row >=0 && col < m && col >=0) return true;
        return false;
    }
    void dfs(int row, int col, vector<vector<bool>>&visited, vector<vector<int>>&grid){
        visited[row][col] = true;
        for(int i =0;i<4;i++){
            int newR = row+delrow[i];
            int newC = col+delcol[i];
            if(isSafe(newR, newC, grid) && !visited[newR][newC] && grid[newR][newC] == 1){
                dfs(newR, newC, visited, grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        //run for the four boundaries and make every 1 to 0 if it is connected to 1 in the boundary;
        

        //first and last row;
        for(int i=0;i<m;i++){
            //first row;
            if(grid[0][i] ==  1 && !visited[0][i]) dfs(0, i, visited, grid);
             //last row
             if(grid[n-1][i] == 1 && !visited[n-1][i]) dfs(n-1, i, visited, grid); 
        }

        //for first and last col
        for(int i =0;i<n;i++){

            //first col
            if(!visited[i][0] && grid[i][0] == 1) dfs(i, 0, visited, grid);

            //last col
            if(!visited[i][m-1] && grid[i][m-1] == 1) dfs(i, m-1, visited, grid);
        }
        int oneCount =0;
        for(int i =0;i<n;i++)for(int j =0;j<m;j++){
            if(!visited[i][j] && grid[i][j] == 1) oneCount+=1;
        }
        return oneCount;
    }
};