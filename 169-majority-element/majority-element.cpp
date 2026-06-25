class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=nums[0];
        int f=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==element){
                f++;
            }
            else{
                f--;
                if(f==0){
                    element=nums[i];
                    f++;
                }
            }
        }
        return element;
    }
};