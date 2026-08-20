class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result;
        vector<int> a;
        vector<int> b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);

        for(int i=2; i<nums.size(); i++){
            if(a.back()>b.back()){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        result=a;
        for(int i=0; i<b.size(); i++){
            result.push_back(b[i]);
        }
        return result;


    }
};