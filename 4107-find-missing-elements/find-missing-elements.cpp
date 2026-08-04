class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        if(nums[nums.size()-1]-nums[0]+1==nums.size()){
            return {};
        }
        
        int x=0;
        int y=0;
        for(int i=0; i<nums.size(); i++){
            if(i+1<nums.size() && nums[i+1]!=nums[i]+1){
                x=nums[i];
                y=nums[i+1];
                for(int i=x+1; i<y; i++){
                    ans.push_back(i);
                }
            }
        }

        
           return ans;
    }
};