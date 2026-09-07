typedef pair<int, pair<int,int>> P;
class Solution {
private:
    bool isSafe(int i, int j, vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if( i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }
public:
    vector<int>delrow = {-1, -1, 0, 1, 1,  1,  0, -1};
    vector<int>delcol = { 0,  1, 1, 1, 0, -1, -1, -1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<vector<int>>result(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}}); // since inserting source to start
        result[0][0]= 0;

        while(!pq.empty()){
            int d = pq.top().first;
            pair<int, int> p = pq.top().second;
            int x = p.first;
            int y = p.second;
            if(d > result[x][y]) continue;
            pq.pop();
            for(int i =0;i<8;i++){
                int x_= x+delrow[i];
                int y_= y+delcol[i];
                int ahead =1;
                if(isSafe(x_, y_, grid) && grid[x_][y_] == 0 && d+ahead < result[x_][y_] ){
                    result[x_][y_] = d+ahead;
                    pq.push({result[x_][y_], {x_, y_}});
                }
            }
        }
        if(result[n-1][m-1] == INT_MAX) return -1;
        return result[n-1][m-1]+1; //For a path of k moves, the number of cells visited is always k + 1

    }
};