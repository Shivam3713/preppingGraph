class Solution {
public:
    vector<int> size;
    vector<int> parent;
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionFunc(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x == parent_y)
            return;
        if (size[parent_x] > size[parent_y]) {
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        } else {
            size[parent_y] += size[parent_x];
            parent[parent_x] = parent_y;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        size.resize(n * n, 1);
        parent.resize(n * n);
        for (int i = 0; i < n * n; i++)
            parent[i] = i;
        // now we're building dsu that will provide whats the size of each
        // connected grid with 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                int curr = i * n + j;
                for (int dir = 0; dir < 4; dir++) {
                    int newR = i + delrow[dir];
                    int newC = j + delcol[dir];
                    int adj = newR * n + newC;
                    if ((newR >= 0 && newR < n && newC >= 0 && newC < n &&
                         grid[newR][newC] == 1)) {
                        if (find(curr) != find(adj)) {
                            unionFunc(curr, adj);
                        }
                    }
                }
            }
        }

        // now after building the dsu we can search through each 0 and calculate
        // for every 0 the max area if we flip it to a '1'
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;
                // int curr = i*n +j;
                unordered_set<int> comparison;
                for (int dir = 0; dir < 4; dir++) {
                    int newR = i + delrow[dir];
                    int newC = j + delcol[dir];
                    int adj = newR * n + newC;
                    if ((newR >= 0 && newR < n && newC >= 0 && newC < n) &&
                        grid[newR][newC] == 1) {
                        comparison.insert(find(adj));
                    }
                }
                int currSize = 1; // since the cell itself which we are choosing
                                  // to flip from 0 -> 1
                for (auto& root : comparison) {
                    currSize += size[root];
                }

                ans = max(currSize, ans);
            }
        }
        return ans == 0 ? n * n : ans;
    }
};