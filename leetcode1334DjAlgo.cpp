#define P pair<int, int>
class Solution {
public:
    int resultCity(vector<vector<int>>& SPM, int n, int dih) {

        int resCity = -1;
        int resCityCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && SPM[i][j] <= dih) {
                    count++;
                }
            }
            if (count <= resCityCount) {
                resCityCount = count;
                resCity = i;
            }
        }
        return resCity;
    }
    void dijsktra(int n, unordered_map<int, vector<P>>& mp, vector<int>& res,
                  int source) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, source});
        res[source] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > res[node])
                continue;
            for (auto& v : mp[node]) {
                int neighbor = v.second;
                int wt = v.first;
                if (res[neighbor] > res[node] + wt) {
                    res[neighbor] = res[node] + wt;
                    pq.push({res[neighbor], neighbor});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<P>> mp;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            mp[u].push_back({wt, v});
            mp[v].push_back({wt, u});
        }
        vector<vector<int>> SPM(
            n, vector<int>(n, INT_MAX)); // shortest path matrix
        for (int i = 0; i < n; i++) {
            dijsktra(n, mp, SPM[i], i);
        }

        return resultCity(SPM, n, distanceThreshold);
    }
};