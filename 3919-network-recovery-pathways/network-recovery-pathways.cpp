class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // Adjacency list: node -> {neighbor, cost}
        vector<vector<pair<int, int>>> adj(n);
        set<int> unique_costs;
        
        // Step 1: Filter offline nodes and edges that exceed the total budget 'k'
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];
            
            // Only consider edges where both nodes are online and edge cost <= k
            if (online[u] && online[v] && c <= k) {
                adj[u].push_back({v, c});
                unique_costs.insert(c);
            }
        }
        
        // Agar budget mein koi edge valid hi nahi hai
        if (unique_costs.empty()) {
            return -1;
        }
        
        vector<int> sorted_costs(unique_costs.begin(), unique_costs.end());
        
        // Step 2: Kahn's Algorithm (Topological Sort)
        vector<int> indegree(n, 0);
        for (int u = 0; u < n; ++u) {
            for (const auto& edge : adj[u]) {
                indegree[edge.first]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0 && online[i]) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Step 3: Binary Search on maximum possible minimum-edge cost
        int left = 0, right = sorted_costs.size() - 1;
        int best_score = -1;
        const long long INF = 1e18; // Safe infinity for long long
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int min_c = sorted_costs[mid];
            
            // dp[i] stores minimum cost to reach node 'i' from node '0'
            vector<long long> dp(n, INF);
            dp[0] = 0;
            
            // Traverse nodes in topological order (forward DP)
            for (int u : topo) {
                if (dp[u] == INF) continue; // Unreachable node
                
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int c = edge.second;
                    
                    // Edge is only valid if it meets our minimum cost threshold
                    if (c >= min_c) {
                        dp[v] = min(dp[v], dp[u] + c);
                    }
                }
            }
            
            // Step 4: Check if path to (n-1) is valid within total cost 'k'
            if (dp[n - 1] <= k) {
                best_score = min_c;
                left = mid + 1;  // Try to maximize further
            } else {
                right = mid - 1; // Current threshold is too strict
            }
        }
        
        return best_score;
    }
};