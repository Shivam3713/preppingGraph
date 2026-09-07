typedef pair<int, pair<int, int>> P;
class Solution {    
private:
    bool isSafe(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }
public:
    vector<int>delrow={-1, 0, 1, 0};
    vector<int>delcol={0, 1, 0, -1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>result(n, vector<int>(m, INT_MAX)); //to store min abs difference between each consecutive cell in route/path
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, {0, 0}}); // at source 0, 0 abs difference with itlsef with be 0
        while(!pq.empty()){
            int maxD = INT_MIN;
            int diff = pq.top().first;
            pair<int, int> p = pq.top().second;
            int x = p.first;
            int y = p.second;
            pq.pop();
            for(int i =0;i<4;i++){
                int x_= x+delrow[i];
                int y_= y+delcol[i];
                if(isSafe(x_, y_, n, m) ){
                    int absdiff = abs(heights[x][y]- heights[x_][y_]);
                    maxD = max(absdiff, diff);
                    if(result[x_][y_] > maxD){
                        result[x_][y_] = maxD;
                        pq.push({maxD, {x_, y_}});
                    }
                }
            }
        }
        if(result[n-1][m-1] == INT_MAX) return 0;
        else return result[n-1][m-1];
    }
};