class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        unordered_set<int> s={nums.begin(), nums.end()};
        while(s.contains(ans)){
            ans+=k;
        }
        return ans;
    }
};