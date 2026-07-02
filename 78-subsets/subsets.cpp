class Solution {
public:
    void sub(vector<vector<int>> &ans, vector<int> a, vector<int> nums, int i){

        if(i==nums.size()){
            ans.push_back({a});
            return;
        }

        a.push_back(nums[i]);
        sub(ans, a,nums,i+1 );

        a.pop_back();
        sub(ans, a,nums,i+1 );

    }





    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        int i=0;
        sub(ans,a,nums,i);
        return ans;

    }
};