class Solution {
    vector<int> depth;
    vector<vector<int>> adj, ans;

public:
    int dfs(int node, int parent, int time) {
        depth[node] = time;
        for (int& v : adj[node]) {
            if (v == parent)
                continue; // this means that we're going to the parent of node
                          // that is v

            if (depth[v] == -1) {
                int value = dfs(v, node, time + 1);
                if (value > time)
                    ans.push_back({v, node});
                time = min(time, value);

            } else {
                time = min(time,
                           depth[v]); // already visited node so we'll take the
                                      // min of the low and the depth of v
            }
        }
        return time;
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        depth.resize(n, -1);
        adj.resize(n, {});
        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, 0); // source, parent, depth/time
        return ans;
    }
};