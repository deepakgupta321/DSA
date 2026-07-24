class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int> xor1;
        unordered_set<int> ans;


        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                xor1.insert(nums[i] ^ nums[j]);
            }
        }

        for(auto h: xor1){
            for(int i=0; i<nums.size(); i++){
                ans.insert(h xor nums[i]);
            }
        }
        

        return ans.size();

        
    }
};