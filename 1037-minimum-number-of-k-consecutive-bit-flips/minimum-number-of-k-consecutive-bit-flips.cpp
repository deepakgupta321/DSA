class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<int> dq;
        int result = 0;
        int ff = 0;
        int j = 0;

        while (j < nums.size()) {
            
            // Window maintenance (Yeh tumhara ekdum sahi hai!)
            if (dq.size() == k) {
                if (dq.front() == 1) {
                    ff = ff - dq.front();
                }
                dq.pop_front();
            }

            // Flip requirement check
            if ((nums[j] == 0 && ff % 2 == 0) || (nums[j] == 1 && ff % 2 != 0)) {
                
                // 🚨 NAYA ADDITION: Kya flip karne ki jagah bachi hai?

                if (j + k > nums.size()) {
                    return -1; // Agar jagah nahi hai, toh possible hi nahi hai
                }

                ff++;
                result++;
                dq.push_back(1);
            } 

            
            else {
                dq.push_back(0);
            }
            
            j++;
        }

        // HATA DIYA: dq.back() == 1 wala logic. Uski zaroorat hi nahi ab.

        return result;
    }
};