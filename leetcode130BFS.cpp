class Solution {
vector<int>delrow = {-1, 0, 1, 0};
vector<int>delcol = {0, 1, 0, -1};
private:
    bool isSafe(int row,int col, vector<vector<char>>&board){
        int n = board.size();
        int m = board[0].size();
        if(row >= 0 && row< n && col >=0 && col < m) return true;
        return false;

    }
    void bfs(int row, int col, vector<vector<bool>>&visited, vector<vector<char>>&board){
        visited[row][col]= true;
        queue<pair<int, int>>q;
        q.push({row, col});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            for(int i =0;i<4;i++){
                int newR = row+delrow[i];
                int newC = col+delcol[i];
                if(isSafe(newR, newC, board) && !visited[newR][newC] && board[newR][newC] == 'O'){
                    q.push({newR, newC});
                    visited[newR][newC] = true;
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m ,false));
        // run bfs from last row first row, first col and last col
        

        for(int i=0;i<m;i++){
            //for first row 
            if(!visited[0][i] && board[0][i] ==  'O'){
                bfs(0, i, visited, board);
            }

            //last row
            if(!visited[n-1][i] && board[n-1][i] == 'O'){
                bfs(n-1, i, visited, board);
            }

        }
        for(int i =0;i<n;i++){
            //first col
            if(!visited[i][0] && board[i][0] == 'O'){
                bfs(i, 0, visited, board);
            }
            //last col
            if(!visited[i][m-1] && board[i][m-1] == 'O'){
                bfs(i, m-1, visited, board);
            }
        }
        for(int i =0;i<n;i++)for(int j =0;j<m;j++){
            if(visited[i][j] == 0) board[i][j] = 'X';
            if(visited[i][j] == 1) board[i][j] = 'O';
        }
    }
};