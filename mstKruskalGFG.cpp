class Solution {
	public:
	vector<int>rank;
	vector<int>parent;
	int find(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find(parent[x]);
	}
	void unionFunc(int x, int y) {
		int parent_x = find(x);
		int parent_y = find(y);
		if (rank[parent_x] > rank[parent_y]) {
			parent[parent_y] = parent_x;
		}
		else if (rank[parent_x] < rank[parent_y]) {
			parent[parent_x] = parent_y;
		}
		else {
			parent[parent_x] = parent_y;
			rank[parent_y]++;
		}
	}
	int kruskal(vector<vector<int>> &vec) {
		int sum = 0;
		for (auto &temp : vec) {
			int u = temp[0];
			int v = temp[1];
			int wt = temp[2];
			
			int parent_u = find(u);
			int parent_v = find(v);
			if (parent_u != parent_v) {
				unionFunc(u, v);
				sum += wt;
			}
		}
		return sum;
	}
	int primMST(vector<vector<vector<int>>> &adj) {
		// code here
		parent.resize(adj.size());
		rank.resize(adj.size(), 0);
		for (int i = 0; i<adj.size(); i++)
			parent[i] = i;
		vector<vector<int>> vec;
		for (int u = 0; u<adj.size(); u++) {
			for (auto &temp : adj[u]) {
				int v = temp[0];
				int wt = temp[1];
				vec.push_back({u, v, wt});
			}
		}
		auto comparator = [&](vector<int>&v1, vector<int>&v2) {return v1[2] < v2[2]; };
		sort(vec.begin(), vec.end(), comparator);
		return kruskal(vec);
	}
};
