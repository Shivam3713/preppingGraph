class Solution {
public:
    int resultCity(vector<vector<int>>&SPM, int n, int dih){
        int result =-1;
        int resCount = INT_MAX;
        for(int i =0;i<n;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                if(SPM[i][j] <= dih) count++;
            }
            if(count <= resCount){
                resCount = count;
            }
            result=i;
        }
        return result;
    }
    void bellmanFord(int n, vector<vector<int>>&edges, vector<int>&res){
        for(int i=0;i<n-1;i++){
            for(auto & edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(res[u] != INT_MAX && res[v] > res[u]+wt){
                    res[v] = res[u]+wt;
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>SPM(n, vector<int>(n, INT_MAX));
        for(int i =0;i<n;i++){
            if(i!=j){
                bellmanFord(n, edges, SPM[i]);
            }
        }
        return resultCity(SPM, n, distanceThreshold);


    }
};