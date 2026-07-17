#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // Sabse bada number nikal lo size define karne ke liye
        int max_val = *max_element(nums.begin(), nums.end());
        
        // 1. Frequency of each number
        vector<long long> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // 2 & 3. Exact GCD pairs count calculate karna (Inclusion-Exclusion)
        vector<long long> exact_gcd(max_val + 1, 0);
        
        // Ulta loop chalayenge (max_val se 1 tak)
        for (int i = max_val; i >= 1; i--) {
            long long multiples_count = 0;
            // 'i' ke saare multiples ki total frequency nikalo
            for (int j = i; j <= max_val; j += i) {
                multiples_count += freq[j];
            }
            
            // 'i' ke multiples se banne wale total possible pairs (nC2 form)
            long long pairs = (multiples_count * (multiples_count - 1)) / 2;
            
            // Un pairs ko minus karo jinka exact GCD 'i' ka koi bada multiple hai (like 2i, 3i...)
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= exact_gcd[j];
            }
            
            exact_gcd[i] = pairs;
        }
        
        // 4. Prefix Sum array banana
        vector<long long> prefix(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            prefix[i] = prefix[i - 1] + exact_gcd[i];
        }
        
        // 5. Har query ka answer Binary Search (upper_bound) se nikalna
        vector<int> ans;
        for (long long q : queries) {
            // upper_bound wo pehla iterator return karta hai jiski value 'q' se strictly badi ho
            auto it = upper_bound(prefix.begin(), prefix.end(), q);
            // Iterator se index nikalne ke liye prefix.begin() subtract karte hain
            int res = it - prefix.begin();
            ans.push_back(res);
        }
        
        return ans;
    }
};