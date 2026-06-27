class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(),0);
        unordered_map<int,int> m;
        int count=0;

        prefix[0]=nums[0];

        prefix.push_back(0);
        for(int i=1; i<nums.size(); i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        for(int j=0; j<nums.size(); j++){
           
            if(prefix[j]==k){
                count++;
            }
            int val=prefix[j]-k;
            if(m.contains(val)){
                count= count+m[prefix[j]-k];
             }
             m[prefix[j]]++;
            
        }

        return count;

    }
};