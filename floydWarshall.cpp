const int INF = 100000000;
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        for(int via = 0;via<n;via++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    if(grid[i][via]!=INF && grid[via][j] != INF){
                        grid[i][j] = min(grid[i][j], grid[i][via]+grid[via][j]);
                    }
                }
            }
        }
    }
};