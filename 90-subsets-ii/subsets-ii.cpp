class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> &temp, int idx){
        
        ans.push_back(temp);    

        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);  //do ...........

            solve(nums, ans, temp, i+1);

            //not taking current;.....

            temp.pop_back();
            
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0;
        solve(nums, ans, temp, i);
        return ans;
    }
};