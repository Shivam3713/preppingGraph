class Solution {
private:
    bool checkSafeNodedfs(int node, vector<vector<int>>&graph, vector<bool>&visited,vector<bool>&isSafe, vector<bool>&inRecursion ){
        visited[node]=true;
        inRecursion[node]=true;
        for(int &v:graph[node]){
            
            if(!visited[v]){
                if(checkSafeNodedfs(v, graph, visited, isSafe,inRecursion) == false)return false;
            }
            else{
                if(inRecursion[v]) return false;
                if(isSafe[v] == false) return false;
            }
        }
        isSafe[node]=true;
        inRecursion[node]= false;
        return true;//safe node
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int  n= graph.size();
        vector<bool>visited(n, false), isSafe(n, false), inRecursion(n, false);
        vector<int>res;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                checkSafeNodedfs(i, graph, visited, isSafe, inRecursion);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(isSafe[i])
                res.push_back(i);
        }
        return res;
            }
};