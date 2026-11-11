class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionFunc(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if (rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int components = n;
        for (auto& vec : connections) {
            if (find(vec[0]) != find(vec[1])) {
                components--;
                unionFunc(vec[0], vec[1]);
            }
        }
        return components - 1;
    }
};