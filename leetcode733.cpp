class Solution {
private:
    void dfs(vector<vector<int>>& image, int row, int col, int color, vector<int>&delrow, vector<int>&delcol, int iniColor ){
        if(iniColor == color) return;
        image[row][col] = color;
        for(int i=0;i<4;i++){
            int newR = row+ delrow[i];
            int newC = col+delcol[i];
            if(newR >=0 && newR < image.size() && newC >= 0 && newC <image[0].size() && image[newR][newC] == iniColor && image[newR][newC] != color){
                image[newR][newC] = color;
                dfs(image, newR, newC, color, delrow, delcol , iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //using dfs method
        vector<int>delrow = {-1, 0, 1, 0};
        vector<int>delcol = {0, 1, 0, -1};
        int iniColor = image[sr][sc];
        dfs(image, sr, sc, color, delrow, delcol, iniColor);
        return image;
    }
};