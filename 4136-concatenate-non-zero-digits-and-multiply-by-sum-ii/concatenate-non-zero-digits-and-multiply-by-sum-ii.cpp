class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        long long MOD = 1000000007;
        
        // Arrays with clear and readable names
        vector<int> prefixSum(n, 0);
        vector<long long> prefixValue(n, 0);
        vector<int> nonZeroCount(n, 0); 
        vector<long long> powerOf10(n + 1, 1);
        vector<int> ans;

        // Precompute powers of 10 to use later
        for (int i = 1; i <= n; i++) {
            powerOf10[i] = (powerOf10[i - 1] * 10) % MOD;
        }

        int count = 0;
        long long currentValue = 0;

        // Step 1: Build Prefix Arrays
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            
            // Simple if-else for Prefix Sum (No '?' operator)
            if (i == 0) {
                prefixSum[i] = digit;
            } else {
                prefixSum[i] = prefixSum[i - 1] + digit;
            }
            
            // Build Prefix Value and count non-zero digits
            if (digit > 0) {
                currentValue = (currentValue * 10 + digit) % MOD;
                count++;
            }
            prefixValue[i] = currentValue;
            nonZeroCount[i] = count;
        }

        // Step 2: Answer the Queries
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            long long sum = 0;
            long long x = prefixValue[r];
            
            // Calculate Sum using simple if-else
            if (l > 0) {
                sum = prefixSum[r] - prefixSum[l - 1];
            } else {
                sum = prefixSum[r];
            }
            
            // Calculate actual number (X) by removing extra prefix
            if (l > 0) {
                int digitsToRemove = nonZeroCount[r] - nonZeroCount[l - 1];
                long long prefixToSubtract = (prefixValue[l - 1] * powerOf10[digitsToRemove]) % MOD;
                
                // Add MOD before modulo to prevent negative values in C++
                x = (x - prefixToSubtract + MOD) % MOD;
            }
            
            // Final multiplication
            long long finalAns = (sum * x) % MOD;
            ans.push_back(finalAns);
        }
        
        return ans;
    }
};