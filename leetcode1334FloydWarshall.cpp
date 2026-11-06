const int INF = 10000 + 1;
class Solution {
public:
    int resultCity(vector<vector<int>>& SPM, int n, int dih) {
        int ans = -1;
        int ansCount = INF;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (SPM[i][j] <= dih) {
                    count++;
                }
            }
            if (count <= ansCount) {
                ansCount = count;
                ans = i;
            }
        }
        return ans;
    }
    void floydWarshall(int n, vector<vector<int>>& SPM) {
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
            SPM[i][i] = 0;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }
        floydWarshall(n, SPM);
        return resultCity(SPM, n, distanceThreshold);
    }
};