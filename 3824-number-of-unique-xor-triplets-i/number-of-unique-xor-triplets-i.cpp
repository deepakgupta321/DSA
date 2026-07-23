class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1 or nums.size()==2){
            return nums.size();
        }

        int ans=1;
        while(ans<=nums.size()){
            ans*=2;
        }
        return ans;

    }
};