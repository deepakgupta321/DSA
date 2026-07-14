class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[201][201][201];

    int solve(int i, int g1, int g2, vector<int>& nums) {
        if (i == nums.size()) {
            return (g1 == g2 && g1 != 0);
        }

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;

        // Skip current element
        ans = solve(i + 1, g1, g2, nums);

        // Put in first subsequence
        ans = (ans + solve(i + 1, gcd(g1, nums[i]), g2, nums)) % MOD;

        // Put in second subsequence
        ans = (ans + solve(i + 1, g1, gcd(g2, nums[i]), nums)) % MOD;

        return dp[i][g1][g2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};