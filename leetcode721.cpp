class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionFunc(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (rank[parent_x] > rank[parent_y])
            parent[parent_y] = parent_x;
        else if (rank[parent_x] < rank[parent_y])
            parent[parent_x] = parent_y;
        else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.resize(n);
        parent.resize(n);
        unordered_map<string, int> mailAccount;
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int user = 0; user < n; user++) {
            for (int mail = 1; mail < accounts[user].size(); mail++) {
                if (mailAccount.find(accounts[user][mail]) ==
                    mailAccount.end()) {
                    mailAccount[accounts[user][mail]] = user;
                } else {
                    unionFunc(user, mailAccount[accounts[user][mail]]);
                }
            }
        }
        // arrange mail
        unordered_map<int, vector<string>> final;
        for (auto& vec : mailAccount) {
            string mail = vec.first;
            int id = vec.second;
            int root = find(id);
            final[root].push_back(mail);
        }
        vector<vector<string>> ans;

        for (auto& it : final) {
            int user = it.first;
            vector<string> temp;
            temp.push_back(accounts[user][0]);
            sort(begin(it.second), end(it.second));
            for (string s : it.second) {
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};