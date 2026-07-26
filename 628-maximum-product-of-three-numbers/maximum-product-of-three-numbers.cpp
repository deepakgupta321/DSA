class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n=nums.size()-1;
        int x=nums[n];
        int y=nums[n-1];
        int z=nums[n-2];

        if(nums[0]<0 && nums[1]<0 && nums[n]>0){
            int r1=nums[0]*nums[1]*nums[n];
            int r2=x*y*z;
            int y=max(r1,r2);
            return y;
        }
        
            return x*y*z;
        
        

    }
};