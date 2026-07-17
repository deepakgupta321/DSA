class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int ones = 0;
        int ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 1)
                ones++;

            while ((j - i + 1) - ones > k) {
                if (nums[i] == 1)
                    ones--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};