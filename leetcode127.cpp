class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(begin(wordList), end(wordList));
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto p= q.front();
                string s = p.first;
                int steps = p.second;
                q.pop();
                if(s == endWord) return steps;
                for(int i=0;i<s.size();i++){
                    char temp = s[i];
                    for(char ch ='a'; ch <='z'; ch++){
                        s[i]= ch;
                        if(st.find(s) != st.end()){
                            q.push({s, steps+1});
                            st.erase(s);
                        }
                    }
                    s[i]= temp;
                }
            }
        }
        return 0;
        
        
    }
};