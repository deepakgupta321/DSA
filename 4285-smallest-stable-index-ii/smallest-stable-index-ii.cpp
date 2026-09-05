class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxe(nums.size(),0);
        vector<int> mine(nums.size(), 0);

        maxe[0]=nums[0];
        mine[mine.size()-1]=nums[nums.size()-1];

        for(int i=1; i<nums.size(); i++){
            if(maxe[i-1]<nums[i]){
                maxe[i]=nums[i];
            }
            else{
                maxe[i]=maxe[i-1];
            }
        }
        for(int i=nums.size()-2; i>=0; i--){
            if(mine[i+1]>nums[i]){
                mine[i]=nums[i];
            }
            else{
                mine[i]=mine[i+1];
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(maxe[i]-mine[i]<=k){
                return i;
            }
        }
        return -1;

    }
};