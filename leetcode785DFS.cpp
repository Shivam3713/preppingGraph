class Solution {
private:
    bool dfs(int node, vector<vector<int>>&graph, vector<int>&color, int currColor){
        color[node]= currColor;
        for(int &v : graph[node]){
            if(color[v] == -1) if(!dfs(v, graph, color, !currColor)){
                return false;
            };
            if(color[v] == currColor) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // since this is already in form of map, dont need to create an unordered_map
        int currColor = 1;
        vector<int>color(graph.size(), -1);
        for(int i =0;i<graph.size();i++){
            if(color[i] == -1){
                if(!dfs(i, graph, color, 1)){
                    return false;
                }
            }   
        }
        return true;

    }
};