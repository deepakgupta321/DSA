class Solution {
public:
    void cm(vector<vector<int>> &ans, vector<int> &temp,vector<int> &nums,  int sum, int target, int i){

        if(sum>target){
           
            return;
        }
        if(sum==target or i>=nums.size()){
            if(sum==target){
                sum-=nums[i];
                ans.push_back(temp);
                return;
            }
            return;
        }
        
    
        temp.push_back(nums[i]);
        sum+=nums[i];
        cm(ans, temp,nums,sum, target, i);
        
        sum-=nums[i];
        temp.pop_back();
        
        cm(ans, temp,nums,sum, target, i+1);
        
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int sum=0;
        vector<int> temp;
        int i=0;

        cm(ans, temp,nums, sum, target, i);
        return ans;
    }
};