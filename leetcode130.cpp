class Solution {
vector<int>delrow={-1, 0, 1, 0};
vector<int>delcol = {0, 1, 0, -1};
private:
    bool isSafe(int row,int col, vector<vector<int>>&visited){
        if(row>=0 && row<visited.size() && col>=0 && col < visited[0].size())return true;
        return false;
    }
    void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&board){
        visited[row][col]= 1;
        for(int i=0;i<4;i++){
            int newR = row+delrow[i];
            int newC= col+delcol[i];
            if(isSafe(newR,newC, visited) && !visited[newR][newC] && board[newR][newC]  == 'O'){
                dfs(newR, newC, visited, board);
            }
        }


    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        //first and the last row
        for(int j =0;j<m;j++){
            if(!visited[0][j] && board[0][j] =='O'){
                dfs(0, j, visited, board);
            }
            if(!visited[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, visited, board);
            }
        }

        //for first and last col
        for(int i =0;i<n;i++){
            if(!visited[i][0] && board[i][0] =='O'){
                dfs(i, 0, visited, board);
            }
            if(!visited[i][m-1] && board[i][m-1]== 'O'){
                dfs(i, m-1, visited, board);
            }
        }
        for(int i =0;i<n;i++)for(int j =0;j<n;j++){
            if(visited[i][j] == 0) board[i][j] = 'X';
            if(visited[i][j] == 1) board[i][j] = 'O';
        }
        


        
    }
};