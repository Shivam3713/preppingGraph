class Solution {
vector<int>delrow = {-1,0,1, 0};
vector<int>delcol = {0, 1, 0, -1};
private:
    bool isSafe(int row, int col, vector<vector<int>>&mat){
        if(row < mat.size() && row >=0 && col < mat[0].size() && col >=0) return true;
        return false;

    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>matrix(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j]= true;
                    matrix[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<pair<int, int>, int>p = q.front();
                int row = p.first.first;
                int col = p.first.second;
                int steps = p.second;
                q.pop();

                for(int i =0;i<4;i++){
                    int newR = row+delrow[i];
                    int newC = col+delcol[i];
                    if(isSafe(newR, newC, mat) && !visited[newR][newC] && mat[newR][newC] == 1){
                        visited[newR][newC] = true;
                        matrix[newR][newC] = steps+1;
                        q.push({{newR, newC},steps+1 });  
                    }
                    
                }
            }
        }
        return matrix;
    }
};