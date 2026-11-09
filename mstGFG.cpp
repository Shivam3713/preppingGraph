class Solution {
	public:
	int primMST(vector<vector<vector<int>>> &adj) {
		// code here
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		int sum = 0;
		// we also need to check if the nodes have already been visited to ensure no TLE
		vector<bool>inMST(adj.size(), false);
		// since no source is given i'll start from 0 with edge weight of 0 and push in pq
		// {weight, source}
		pq.push({0, 0});
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			int weight = p.first;
			int node = p.second;
			if (inMST[node])
				continue;
			inMST[node] = true;
			sum += weight;
			for (auto & v : adj[node]) {
				int neighbor = v[0];
				int neighborWt = v[1];
				if (inMST[neighbor])
					continue;
				else
					pq.push({neighborWt, neighbor});
			}
		}
		return sum;
	}
};
