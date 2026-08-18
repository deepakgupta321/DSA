class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        vector<int> v(51);
        int ans=-1;

        for(int i=0; i<nums.size(); i++){
            vector<int> v1(51);
            int size=k;
            int j=i;
            while(nums.size()-i>=k && size--){
                if(v1[nums[j]]==0){
                    v1[nums[j]]=1;
                }
                j++;
            }
            for(int n=0; n<51; n++){
                if(v1[n]>0){
                    v[n]++;
                }
            }
        }

        for(int i=0; i<51; i++){
            if(v[i]==1){
                ans=max(ans, i);
            }
        }
           

           return ans;


    }
};