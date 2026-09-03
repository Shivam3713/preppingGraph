class Solution {
private:
    bool dfs(int node, vector<bool>&visited, vector<bool>&isSafe, vector<bool>&inRecursion, vector<vector<int>>&graph){
        visited[node] = true;
        inRecursion[node] = true;
        //ab is node se jaha jaha ja sakte hai uske liye code likho
        for(int &v: graph[node]){

            if(!visited[v]){
                
                if(dfs(v, visited, isSafe, inRecursion, graph) == true){
                    return true;
                }
            }
            if(inRecursion[v]) {
                isSafe[v]= false;
                return true; //agar ye node humare path mein hai toh return true  kardo
            }  
        }

        //agar ye node leaf node hua toh aur upar for wale loop mein hum gaye hi nahi kyuki iska outdegree 0 hai toh
        inRecursion[node]= false;
        isSafe[node]=true;
        return false; // since cycle nahi mila

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
       
        vector<bool>visited(n, false), isSafe(n, false), inRecursion(n, false);


        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited, isSafe, inRecursion, graph);
            }
        }
        vector<int>res;
        for(int i =0;i<isSafe.size();i++){
            if(isSafe[i] == true )res.push_back(i);
        }
        return res;
    }
};