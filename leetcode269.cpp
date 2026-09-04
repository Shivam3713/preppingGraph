class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		unordered_map<int, set<char>> mp;
		set<char>st;
		// collect all unique characters from words vector
		for (string word: words) {
			for (char ch : word) {
				st.insert(ch);
			}
		}
		
		// now make the graph relation of one character to another in order
		vector<int>indegree(26, 0);
		for (int i = 0; i<words.size() - 1; i++) {
			string first = words[i];
			string second = words[i + 1];
			int len = min(first.size(), second.size());
			for (int k = 0; k<len; k++) {
				char u = first[k];
				char v = second[k];
				if (u != v) {
					if (mp[u].insert(v).second) {
						indegree[v - 'a']++;
					}
						break;
					if (k + 1 == len && first.size() > second.size()) {
						// we have the wrong order;
						mp.clear();
						return "";
					}
				}
			}
		}
		queue<char>q;
			for (int i = 0; i<indegree.size(); i++) {
				if (indegree[i] == 0 && st.count(i + 'a')) {
					q.push(i + 'a');
				}
			}
			vector<char>res;
			while (!q.empty()) {
				char letter = q.front();
				q.pop();
				res.push_back(letter);
				for (char ch : mp[letter]) {
					indegree[ch - 'a']--;
					if (indegree[ch - 'a'] == 0)
						q.push(ch);
				}
			}
			if (st.size()
				 != res.size())return "";
			string ans = "";
			for (char ch : res) {
				ans += ch;
			}
			return ans;
			
		
	}
	};
