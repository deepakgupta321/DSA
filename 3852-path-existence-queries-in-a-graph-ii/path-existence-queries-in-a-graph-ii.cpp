#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> unique_vals = nums;
        
        // 1. Array ko sort aur deduplicate karna
        sort(unique_vals.begin(), unique_vals.end());
        unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
        
        int m = unique_vals.size();
        int LOG = 20; 
        vector<vector<int>> up(m, vector<int>(LOG, 0));
        
        // 2. Base case: 1 jump (2^0 steps) mein furthest index kahan tak ja sakte hain
        for (int i = 0; i < m; ++i) {
            auto it = upper_bound(unique_vals.begin(), unique_vals.end(), unique_vals[i] + maxDiff);
            up[i][0] = distance(unique_vals.begin(), it) - 1;
        }
        
        // 3. Binary Lifting table pre-compute karna
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < m; ++i) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        // 4. Queries process karna
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            // Same node query
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int val_u = nums[u];
            int val_v = nums[v];
            
            // Direct edge mojood hai
            if (abs(val_u - val_v) <= maxDiff) {
                ans.push_back(1);
                continue;
            }
            
            // Undirected graph mein hamesha left se right (chhoti se badi value) ki taraf calculate karna easy hai
            if (val_u > val_v) {
                swap(val_u, val_v);
            }
            
            int A = lower_bound(unique_vals.begin(), unique_vals.end(), val_u) - unique_vals.begin();
            int B = lower_bound(unique_vals.begin(), unique_vals.end(), val_v) - unique_vals.begin();
            
            // Agar full jumps lagane ke baad bhi target B tak nahi pahonch paye
            if (up[A][LOG - 1] < B) {
                ans.push_back(-1);
            } else {
                int steps = 0;
                int curr = A;
                
                // Binary lifting ka logic
                for (int k = LOG - 1; k >= 0; --k) {
                    if (up[curr][k] < B) {
                        curr = up[curr][k];
                        steps += (1 << k);
                    }
                }
                
                steps += 1;
                ans.push_back(steps);
            }
        }
        
        return ans;
    }
};