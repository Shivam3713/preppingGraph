# Striver Graph Series + CodeStoryWithMIK — Grouped by Concept

Merged and concept-sorted list from:
- [Striver's Graph Series (YouTube)](https://www.youtube.com/playlist?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) / [takeUforward notes](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions)
- [Graph Concepts & Qns: Convert Story To Code — codestorywithMIK (YouTube)](https://www.youtube.com/playlist?list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY) / [GitHub repo](https://github.com/MAZHARMIK/Interview_DS_Algo/tree/master/Graph)

> ⚠️ "Solution" column: links to codestorywithMIK's GitHub source file where confirmed. Rows marked 🔶 have no confirmed codestorywithMIK file — linked to the general takeUforward sheet instead. Verify against the video before relying on it.

> This version regroups the original sheet's rows by the **actual technique** used to solve each problem (rather than the broad section headers), so problems that share a pattern sit together even if they came from different sections originally. A couple of problems genuinely span two techniques (e.g. Making a Large Island, Swim in Rising Water) — they're listed once under their most common approach, with the alternative noted.

## Progress Tracker

- [ ] Basics (Traversal Fundamentals)
- [ ] Grid BFS/DFS (Flood-fill / Multi-source BFS)
- [ ] Bipartite Check
- [ ] BFS on Implicit Graph
- [ ] Graph Cloning
- [ ] Topological Sort
- [ ] Dijkstra's Algorithm
- [ ] Bellman-Ford / Constrained BFS
- [ ] Floyd-Warshall
- [ ] Union-Find / Disjoint Set
- [ ] Bridges & Articulation Points
- [ ] Strongly Connected Components

## Problems

### Basics (Traversal Fundamentals)

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 1 | BFS Traversal | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/BFS_Traversal.cpp) |
| 2 | DFS Traversal (Iterative & Recursive) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/DFS%20Traversal%20%28Iterative%20%26%20Recursive%29) |
| 3 | Number of Provinces | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/BFS_DFS/Number%20of%20Provinces.cpp) |

### Grid BFS/DFS (Flood-fill / Multi-source BFS)

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 4 | Flood Fill | 733 | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 5 | Rotting Oranges (multi-source BFS) | 994 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Multi-Source%20BFS/Rotting%20Oranges.cpp) |
| 6 | Cycle Detection – Undirected (BFS) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Detect%20cycle%20in%20an%20undirected%20graph%20%28BFS%29.cpp) |
| 7 | Cycle Detection – Undirected (DFS) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Detect%20cycle%20in%20an%20undirected%20graph%20%28DFS%29.cpp) |
| 8 | 01 Matrix / Distance of Nearest 1 (multi-source BFS) | 542 | Both | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 9 | Surrounded Regions | 130 | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 10 | Number of Enclaves | 1020 | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 11 | Number of Distinct Islands | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Number%20of%20Distinct%20Islands) |
| 12 | Number of Islands | 200 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Number%20of%20Islands.cpp) |
| 15 | Cycle Detection – Directed (DFS) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Detect%20cycle%20in%20a%20directed%20graph%20%28DFS%29.cpp) |
| 16 | Cycle Detection – Directed (BFS/Kahn's) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Detect%20cycle%20in%20a%20directed%20graph%20%28BFS%29.cpp) |

### Bipartite Check

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 13 | Is Graph Bipartite? (BFS) | 785 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Bipartite%20Graph.cpp) |
| 14 | Is Graph Bipartite? (DFS) | 785 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Bipartite%20Graph.cpp) |

### BFS on Implicit Graph

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 17 | Word Ladder I | 127 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Word_Ladder.cpp) |
| 18 | Word Ladder II (BFS + path reconstruction) | 126 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Word%20Ladder%20II.cpp) |

### Graph Cloning

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 19 | Clone Graph | 133 | codestorywithMIK | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Clone%20Graph.cpp) |

### Topological Sort

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 20 | Topological Sort (DFS) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Topological%20Sort%20%28DFS%29.cpp) |
| 21 | Topological Sort (BFS/Kahn's) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Topological%20Sort%20%28BFS-Kahn%27s%20Algorithm%29.cpp) |
| 22 | Course Schedule | 207 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Course%20Schedule.cpp) |
| 23 | Course Schedule II | 210 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Course%20Schedule%20II.cpp) |
| 24 | Find Eventual Safe States (reverse-graph topo sort) | 802 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Find%20Eventual%20Safe%20States.cpp) |
| 25 | Alien Dictionary | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Alien%20Dictionary.cpp) |
| 26 | Shortest Path in DAG (topo sort + relaxation) | GFG | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |

### Dijkstra's Algorithm

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 27 | Shortest Path – Undirected, Unit Weights (plain BFS) | GFG | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 28 | Dijkstra's Algorithm (Priority Queue) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra%E2%80%99s%20Algorithm%28Priority%20Queue%29.cpp) |
| 29 | Dijkstra's Algorithm (Set) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra%E2%80%99s%20Algorithm%28set%29.cpp) |
| 30 | Shortest Path in Binary Matrix | 1091 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra%27a%20Based%20Problems/Shortest%20Path%20in%20Binary%20Matrix.cpp) |
| 31 | Path With Minimum Effort | 1631 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra%27a%20Based%20Problems/Path%20With%20Minimum%20Effort.cpp) |
| 33 | Network Delay Time | 743 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra%27a%20Based%20Problems/Network%20Delay%20Time.cpp) |
| 34 | Number of Ways to Arrive at Destination | 1976 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra%27a%20Based%20Problems/Number%20of%20Ways%20to%20Arrive%20at%20Destination.cpp) |
| 47 | Swim in Rising Water (Dijkstra-style, or binary search + BFS) | 778 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Swim%20in%20Rising%20Water.cpp) |

### Bellman-Ford / Constrained BFS

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 32 | Cheapest Flights Within K Stops | 787 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Cheapest%20Flights%20Within%20K%20Stops.cpp) |
| 35 | Minimum Multiplications to Reach End | GFG | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 36 | Bellman-Ford Algorithm | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Bellman-Ford%20Based%20Problems/Distance%20from%20the%20Source%28Bellman-Ford%20Algorithm%29.cpp) |

### Floyd-Warshall

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 37 | Floyd Warshall Algorithm | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Floyd%20Warshall/Floyd%20Warshall.cpp) |
| 38 | Find City With Smallest # Neighbors at Threshold Distance | 1334 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Floyd%20Warshall/Find%20the%20City%20With%20the%20Smallest%20Number%20of%20Neighbors%20at%20a%20Threshold%20Distance.cpp) |

### Union-Find / Disjoint Set

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 39 | Minimum Spanning Tree – Theory | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Minimum%20Spanning%20Tree%20%28Prim%27s%29) |
| 40 | Disjoint Set (Union by Rank + Path Compression) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Disjoint%20set%20%28Union-Find-Rank%26PathCompression%29.cpp) |
| 41 | MST – Kruskal's Algorithm | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Minimum%20Spanning%20Tree%20%28Kruskal%27s%20Algorithm%29.cpp) |
| 42 | Number of Operations to Make Network Connected | 1319 | codestorywithMIK | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Number%20of%20Operations%20to%20Make%20Network%20Connected.cpp) |
| 43 | Most Stones Removed with Same Row/Column | 947 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Most%20Stones%20Removed%20with%20Same%20Row%20or%20Column.cpp) |
| 44 | Accounts Merge | 721 | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 45 | Number of Islands II (Online) | 305 (Premium) | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |
| 46 | Making a Large Island (DSU, or multi-pass BFS/DFS) | 827 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/BFS_DFS/Making%20A%20Large%20Island.cpp) |

### Bridges & Articulation Points

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 48 | Bridges / Critical Connections in a Network | 1192 | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Critical%20Connections%20in%20a%20Network) |
| 49 | Articulation Point | GFG | Striver | 🔶 [Sheet](https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions) |

### Strongly Connected Components

| # | Problem | LeetCode # | Source | Solution |
|---|---|---|---|---|
| 50 | Strongly Connected Components (Kosaraju's Algo) | GFG | Both | [Code](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Strongly%20Connected%20Components%20%28Kosaraju%27s%20Algo%29.cpp) |
