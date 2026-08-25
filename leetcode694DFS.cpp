#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<int>delrow = {-1, 0, 1, 0};
vector<int>delcol = {0, 1, 0, -1};
private:
    bool isSafe(int row, int col, vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(row<n && row>=0 && col<m && col >=0) return true;
        return false;
    }
    void dfs(int row, int col, int baseRow, int baseCol, vector<vector<bool>>&visited, vector<vector<int>>&grid, vector<pair<int, int>>&res){
        visited[row][col] = true;
        res.push_back({row-baseRow, col-baseCol});
        for(int i = 0;i<4;i++){
            int newR = row+delrow[i];
            int newC = col+delcol[i];
            if(isSafe(newR, newC, grid) && !visited[newR][newC] && grid[newR][newC]==1){
                // res.push_back({newR-baseRow, newC-baseCol});
                dfs(newR, newC, baseRow, baseCol, visited, grid, res);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        set<vector<pair<int, int>>>st;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j] == 1){
                vector<pair<int, int>>res;
                dfs(i, j, i, j, visited, grid, res);
                st.insert(res);
                
            }
        }
        return st.size();
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

    cout << obj.countDistinctIslands(grid) << endl;

    return 0;
}