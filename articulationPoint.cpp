class Solution {
	vector<int>depth;
	vector<vector<int>> adj;
	vector<int>ans;
	public:
	int dfs(int node, int parent, int time, vector<int>&mark) {
		depth[node] = time;
		int low = time;
		int children = 0;
		for (int &v: adj[node]) {
			if (v == parent)
				continue;
			if (depth[v] == -1) { // not visited
				children++;
				int value = dfs(v, node, time + 1, mark);
				if (value >= time && parent != -1) {
					
					mark[node] = 1;
				}
				low = min(low, value);
			}
			else {
				low = min(low, depth[v]);
			}
			if (parent == -1 && children > 1)
				mark[node] = 1;
		}
		return low;
	}
	vector<int> articulationPoints(int V, vector<vector<int>> & edges) {
		// code here
		depth.resize(V, -1);
		adj.resize(V, {});
		vector<int>mark(V, 0);
		for (auto &edge: edges) {
			int u = edge[0];
			int v = edge[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i<V; i++) //since if the graph is split into various components then
			dfs(i, -1, 0, mark); // source , parent , time , marking node array;
		for (int i = 0; i<mark.size(); i++) {
			if (mark[i] == 1)
				ans.push_back(i);
		}
		return ans.size() > 0 ? ans: vector<int> {-1};
		
	}
};
