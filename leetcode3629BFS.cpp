class Solution {
public:
    vector<bool>isPrime;
    void buildSieve(int maxEle){
        isPrime.resize(maxEle+1, true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int num= 2;num*num<=maxEle;num++){
            if(isPrime[num]){
                for(int multiple = num*num;multiple<=maxEle;multiple+=num){
                    isPrime[multiple]=false;
                }
            }
        }


    }
    int minJumps(vector<int>& nums) {
        int n  = nums.size();
        unordered_map<int, vector<int>>mp;
        int maxEle = 0;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            maxEle = max(maxEle, nums[i]);
        }

        buildSieve(maxEle);

        queue<int>q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0]=true;
        unordered_set<int>seen;
        int steps =0;
        while(!q.empty()){
            int size= q.size();
            while(size--){
                int i = q.front();
                q.pop();
                
                //if we are at the last index return steps
                if(i == n-1) return steps;

                if(i-1>=0 && !visited[i-1]){
                    q.push(i-1);
                    visited[i-1]= true;
                }

                if(i+1 <= n-1 && !visited[i+1]){
                    q.push(i+1);
                    visited[i+1]= true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) continue;

                for(int multiple = nums[i]; multiple <= maxEle ; multiple+=nums[i]){
                    if(!mp.contains(multiple)) continue;
                    for(int &j: mp[multiple]){
                        if(!visited[j]){
                            visited[j]= true;
                            q.push(j);
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};