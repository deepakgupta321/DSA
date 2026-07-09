class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> components(n, 0);
        int current_id = 0;
        
        // Adjacent elements ka difference check karke components banao
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_id++;
            }
            components[i] = current_id;
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
        
        // Queries ka answer O(1) mein do
        for (const auto& q : queries) {
            ans.push_back(components[q[0]] == components[q[1]]);
        }
        
        return ans;
    }
};