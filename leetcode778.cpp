typedef pair<int, pair<int, int>> P;
class Solution {
private:
    bool isSafe(int x , int y, int n){
        return x>=0 && x<n && y>=0 && y<n;
    }
public:
    vector<int>delrow ={-1, 0, 1, 0};
    vector<int>delcol = {0, 1, 0, -1};

    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<P, vector<P>, greater<P>>pq;
        int n= grid.size();
        vector<vector<int>>result(n, vector<int>(n, INT_MAX));
        result[0][0]= grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            int time = pq.top().first;
            pair<int, int>cell = pq.top().second;
            int x = cell.first;
            int y = cell.second;
            pq.pop();
            if(result[x][y] < time) continue;
            // if(x  == n && y == n) return time;
            for(int i =0;i<4;i++){
                int x_ = x+delrow[i];
                int y_ = y+delcol[i];
                if(isSafe(x_, y_, n)){
                    int newTime = max(time, grid[x_][y_]);
                    if(newTime < result[x_][y_]){
                        result[x_][y_]= newTime;
                        pq.push({newTime, {x_, y_}});
                    }
                }
            }
        }
        if(result[n-1][n-1] == INT_MAX) return -1;
        else return result[n-1][n-1];

    }
};