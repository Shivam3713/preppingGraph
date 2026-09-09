class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        vector<bool>visited(n, false);

        for(int i =0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<int>q;
        q.push(0);
        visited[0]= true;

        int steps =0;

        while(!q.empty()){
            int currSize = q.size();

            while(currSize--){
                int index= q.front();
                q.pop();
                int left = index-1;
                int right = index+1;
                if(index == n-1) return steps;

                if(left >= 0 && !visited[left]){
                q.push(left);
                visited[left]= true;

                }
                if(right<=n-1 && !visited[right]){
                    q.push(right);
                    visited[right]= true;
                }

                for(auto vIndex: mp[arr[index]]){
                    if(!visited[vIndex]){
                        q.push(vIndex);
                        visited[vIndex]= true;
                    }
                }
                mp.erase(arr[index]);
            }
            steps++;
            
        }
        return -1;

    }
};