class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int i=0;
        int j=nums.size()-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(nums[mid]==target){
                
                int high=mid;
                while(mid+1<nums.size() && nums[mid+1]==target){
                    high++;
                    mid++;
                }
                int low=mid;
                while(mid-1>=0 && nums[mid-1]==target){
                    low--;
                    mid--;
                }

                

                return {low, high};
            }

            if(nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

        return {-1,-1};
    }
};