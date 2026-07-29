class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>& nums, vector<int> &temp, int i, int target){

        if(target<0){
            return;
        }

        if(target==0 or i>=nums.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }

        for(int j=i; j<nums.size(); j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            } 

            // explore kar rhe 
            temp.push_back(nums[j]);
            target-=nums[j];
            solve(ans, nums, temp, j+1, target);

            // nhi chahiye current iske next wala check karo

           temp.pop_back();
           target+=nums[j];

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0;

        solve(ans, nums, temp, i, target);
        return ans;
    }
};