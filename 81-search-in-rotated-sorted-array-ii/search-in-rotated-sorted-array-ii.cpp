class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            // Agar target mil gaya
            if (nums[mid] == target) {
                return true;
            }

            // Tricky Case: Jab teeno same hon, hume nahi pata left sorted hai ya right
            // Isliye hum bas boundaries ko shrink kar dete hain
            if (nums[i] == nums[mid] && nums[mid] == nums[j]) {
                i++;
                j--;
                continue;
            }

            // Left half sorted hai
            if (nums[i] <= nums[mid]) {
                // Check karo agar target is left sorted half mein hai
                if (nums[i] <= target && target < nums[mid]) {
                    j = mid - 1; // Target left mein hai
                } else {
                    i = mid + 1; // Target right mein hoga
                }
            } 
            // Right half sorted hai
            else {
                // Check karo agar target is right sorted half mein hai
                if (nums[mid] < target && target <= nums[j]) {
                    i = mid + 1; // Target right mein hai
                } else {
                    j = mid - 1; // Target left mein hoga
                }
            }
        }

        return false;
    }
};