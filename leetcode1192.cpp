class Solution {
public:
    vector<int> depth;
    vector<vector<int>> adj, ans;
    int dfs(int node, int parent, int time) {
        depth[node] = time;
        int low = time;
        for (int& v : adj[node]) {
            if (v == parent)
                continue; // sine humein wapis parent pe nahi jana hai
            // ek node ko hum 2 condition mein divide karenge, pehela, visited
            // nahi hona chahiye, dusra , agar visited hai toh vo parent nahi
            // hai matlab jis node pe hum jane wale hai vo ek cycle ka part hai
            if (depth[v] == -1) { // agar visited nahi hai toh
                int value = dfs(v, node, time + 1);
                if (time < value) {
                    ans.push_back({v, node});
                }
                low = min(low, value);
            } else {
                low = min(low, depth[v]);
            }
        }
        return low;
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        depth.resize(n, -1);
        adj.resize(n, {});
        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, 0); // source, parent, time
        return ans;
    }
};
