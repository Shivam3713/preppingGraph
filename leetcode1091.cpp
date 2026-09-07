class Solution {
private:
    bool isSafe(int i, int j , vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }
public:
    vector<int>delrow = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int>delcol = { 0,  1, 1, 1, 0, -1,-1, -1 };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int steps=0; //counting the steps needed to go from 0,0 to n-1,m-1
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q; // storing x, y co-ordinates
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1; //check if we can even start valid or end valid
        q.push({0, 0});
        visited[0][0]=true;
        while(!q.empty()){
            int level = q.size(); //currently the number of nodes will be the nodes we can reach 
            while(level--){
                auto p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second; 
                
                if(x == n-1 && y == m-1) return steps +1;
                for(int i =0;i<8;i++){
                    int x_ = x+delrow[i];
                    int y_ = y+delcol[i];
                    if(isSafe(x_, y_, grid) && grid[x_][y_] == 0 && !visited[x_][y_]){
                        q.push({x_,y_});
                        visited[x_][y_]= true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};