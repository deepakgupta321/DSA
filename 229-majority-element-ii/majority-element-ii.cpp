class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0;
        int c2=0;
        int e1=0;
        int e2=0;
        for(int i=0;i<nums.size(); i++){
            if(c1==0 and nums[i]!=e2){
                e1=nums[i];
                c1++;
            }
            else if(c2==0 and nums[i]!=e1){
                e2=nums[i];
                c2++;
            }
            else if(nums[i]==e1){
                c1++;
            }
            else if(e2==nums[i]){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        int k=0;
        int k1=0;
        for(int i=0; i<nums.size(); i++){
            if(e1==nums[i]){
                k++;
            }
            else if(e2==nums[i]){
                k1++;
            }
        }
        int verify=(nums.size()/3);
        vector<int> ans;
        if(verify<k){
            ans.push_back(e1);
        }
        if(verify<k1){
            ans.push_back(e2);
        }

       

        return ans;
    }
};