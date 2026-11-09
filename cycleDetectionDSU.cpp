class Solution {
  public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unionFunc(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent]= x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool detectCycle(int V, vector<int> adj[]) {
        // Code here
        parent.resize(V);
        rank.resize(V, 0);
        for(int i =0;i<V;i++) parent[i]=i;

        for(int u =0;u<V;u++){
            for(auto &v: adj[u]){
                if(u<v){
                    int parent_u = find(u);
                    int parent_v = find(v);
                    if(parent_u == parent_v) return true;
                }
                unionFunc(u, v);
            }
        }
        return false;

    }
};