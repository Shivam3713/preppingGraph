class Solution {
  public:
  const int M = 1e3;
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<int>result(1e3+1, INT_MAX);
        queue<pair<int, int>>q;
        q.push({start, 0});
        result[start] =0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(result[node] < steps) continue;
            if(node == end) return steps;
            for(int &v: arr){
                int currNode  = (v*node) %M;
                if(result[currNode]> 1+steps){
                    result[currNode] = 1+steps;
                    q.push({currNode, 1+steps});
                }
            }
        }
        return -1;

    }
};