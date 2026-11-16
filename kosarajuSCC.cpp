class Solution {
	public:
	void dfs(int node, vector<bool>&visited, vector<vector<int>> &reversedAdj) {
		visited[node] = true;
		for (int v: reversedAdj[node]) {
			if (!visited[v]) {
				dfs(v, visited, reversedAdj);
			}
		}
	}
	void topo(int node, vector<bool>&visited, stack<int>&st, vector<vector<int>> &adj) {
		visited[node] = true;
		for (int v: adj[node]) {
			if (!visited[v]) {
				topo(v, visited, st, adj);
			}
		}
		st.push(node);
		
	}
	int countSCC(vector<vector<int>> & adj) {
		// code here//step 1 to get the topo order and store it in a stack
		int n = adj.size();
		stack<int>st;
		vector<bool>visited(n, false);
		
		for (int i = 0; i<n; i++) {
			if (!visited[i]) {
				topo(i, visited, st, adj);
			}
		}
		
		// step 2 make the reverse of the adj list we got
		vector<vector<int>> reversedAdj(n);
		for (int i = 0; i<n; i++) {
			for (int v: adj[i]) {
				reversedAdj[v].push_back(i);
			}
		}
		visited = vector<bool>(n, false);
		int count = 0;
		while (!st.empty()) {
			int node = st.top();
			st.pop();
			if (!visited[node]) {
				dfs(node, visited, reversedAdj);
				count++;
			}
		}
		return count;
	}
};
