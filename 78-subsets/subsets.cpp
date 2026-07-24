class Solution {
public:
    // void sub(vector<vector<int>> &ans, vector<int> a, vector<int> nums, int i){

    //     if(i==nums.size()){
    //         ans.push_back({a});
    //         return;
    //     }

    //     a.push_back(nums[i]);
    //     sub(ans, a,nums,i+1 );

    //     a.pop_back();
    //     sub(ans, a,nums,i+1 );

    // }

    void sub(vector<int>& nums, vector<int> &temp, int i, vector<vector<int>>& ans){

        if(i>nums.size()-1){
            ans.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[i]);
        sub(nums, temp, i+1, ans);

        //backtrack woh element nhi lena tha////////

        temp.pop_back();
        sub(nums, temp, i+1, ans );
    }





    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> a;
        // int i=0;
        // sub(ans,a,nums,i);
        // return ans;

        vector<vector<int>> ans;
        vector<int> temp;
        int index=0;
        sub(nums, temp, index, ans );

        return ans;


    }
};