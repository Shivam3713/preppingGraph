class Solution {
    public:
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here

          //using kahns algo of making topo order if  nodes put in q count is not equal to V return true; else return false

          unordered_map<int, vector<int>>mp;
          for(int i =0;i<edges.size();i++){
              mp[edges[i][0]].push_back(edges[i][1]);
          }
          //fill indegree vector
          vector<int>indegree(V, 0);
          for(auto &it:mp){
              for(int &v: it.second){
                  indegree[v]++;
              }
          }

          int count=0;
          //push every 0 indegree node in q;
          queue<int>q;
          for(int i=0;i<V;i++){
              if(indegree[i] == 0) q.push(i);
          }

          while(!q.empty()){
              int curr = q.front();
              q.pop();
              count++;
              for(int &v: mp[curr]){
                  indegree[v]--;
                  if(indegree[v] == 0){
                      q.push(v);
                  }
              }
          }
          if(count != V) return true ; //that there is a cycle
          else return false;
      }
  };