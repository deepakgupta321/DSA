class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            int x=0;
            for(int j=i; j<nums.size(); j++){
                if(nums[j]==target){
                    x++;
                }
                int t=j-i+1;
                t=t/2;
                if(x>t){
                    sum++;
                }
            }
        }
        return sum;
    }
};