class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>>parentMap;
        int n= graph.size();
        vector<int>res;
        vector<int>outdegree(n, 0);
        for(int i=0;i<n;i++){
            outdegree[i] = graph[i].size();
            for(int v:graph[i]){
                parentMap[v].push_back(i);
            }
        }
        queue<int>q;
        for(int i =0;i<outdegree.size();i++) if(outdegree[i] == 0)q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int &p: parentMap[node]){
                outdegree[p]--;
                if(outdegree[p] == 0) q.push(p);
            }
           
            }
            sort(begin(res), end(res));
            return res;
        
    }
};