class Solution {
	public:
	vector<int>rank;
	vector<int>parent;
	vector<int>delrow = {-1, 0, 1, 0};
	vector<int>delcol = {0, -1, 0, 1};
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
	
	vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
		vector<int>ans;
		int count = 0;
		rank.resize(n*m, 0);
		parent.resize(n*m);
		// vector<bool>visited(n*m, false);
		vector<vector<int>> grid(n, vector<int>(m, 0));
		for (int i = 0; i<(n*m); i++) {
			parent[i] = i;
		}
		for (auto it: operators) {
			int row = it[0];
			int col = it[1];
			if (grid[row][col] == 1) {
				ans.push_back(count);
				continue;
			}
			grid[row][col] = 1;
			count++;
			for (int i = 0; i<4; i++) {
				int newR = row + delrow[i];
				int newC = col + delcol[i];
				if ((newR >= 0 && newR < n && newC >= 0 && newC <m) && grid[newR][newC] == 1) {
					int curr = (row*m) + col;
					int adj = (newR*m) + newC;
					if (find(curr) != find(adj)) {
						count--;
						unionFunc(curr, adj);
					}
				}
			}
			ans.push_back(count);
			
		}
		return ans;
		
	}
};
