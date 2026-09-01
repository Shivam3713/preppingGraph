class Solution {
private:
    void dfs(unordered_map<string,vector<string>>&parent, string word, string beginWord, vector<string>&path, vector<vector<string>>&ans){
        path.push_back(word);
        if(word == beginWord){
            vector<string>temp = path;
            reverse(begin(temp), end(temp));
            ans.push_back(temp);
            path.pop_back();
            return;
        }
        for(auto &p:parent[word]){
            dfs(parent, p, beginWord, path, ans);
        }
        path.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(begin(wordList), end(wordList));
        if(st.find(endWord) == st.end()) return {};

        vector<string>currentlyUsed;
        int currLevel = 0;

        unordered_map<string, vector<string>>parent; //who reached curr word
        unordered_map<string, int>howfar; //how far from the beginword

        queue<string>q;
        currentlyUsed.push_back(beginWord);
        howfar[beginWord] =0;
        q.push(beginWord);
        while(!q.empty()){
            string word = q.front();
            q.pop();
            if(howfar[word] > currLevel){
                currLevel = howfar[word];
                for(auto &it: currentlyUsed) st.erase(it);
                currentlyUsed.clear();
            }
            string newWord = word;
            for(int i =0;i<word.size();i++){
                char temp =newWord[i];
                for(char ch = 'a';ch<='z';ch++){
                    newWord[i]= ch;
                    if(st.find(newWord) == st.end()) continue;  
                    if(howfar.find(newWord) == howfar.end() ){
                        howfar[newWord] = howfar[word]+1;
                        currentlyUsed.push_back(newWord);
                        parent[newWord].push_back(word);
                        q.push(newWord);
                    }
                    else if(howfar[word]+1 == howfar[newWord]){
                        parent[newWord].push_back(word);
                    }
                }
                newWord[i] = temp;
            }
        }
        if(howfar.find(endWord) == howfar.end()) return {};
        vector<vector<string>>ans;
        vector<string>path;
        dfs(parent, endWord, beginWord, path,ans );
        return ans;
    }
};