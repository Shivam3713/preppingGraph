class Solution {
int time =0;
vector<int>delrow = {-1, 0, 1, 0};
vector<int>delcol = {0, 1, 0, -1};
private:
    bool isSafe(int row, int col, vector<vector<int>>&grid){
        if(row<grid.size() && row >=0 && col <grid[0].size() && col >=0) return true;
        return false;

    }
    void bfs(queue<int>&q, int & fresh, vector<vector<int>>&grid){
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newR = row+delrow[i];
                    int newC = col+delcol[i];
                    if(isSafe(newR, newC, grid)){
                        if(grid[newR][newC] == 1){
                            grid[newR][newC]=2;
                            q.push({newR, newC});
                            fresh--;
                        }
                    }
                }
            }
            time++;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh =0;
        queue<pair<int, int>>q; //for storing and processign rotten oranges

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0; //since initially there's no fresh orange
        return time;
    }
};