class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int c=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                nums[i]=-1;
            } 
        }
        
        for(int i=1; i<nums.size(); i++){
            nums[i]=nums[i-1]+nums[i];
        }

        
        unordered_map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                c=max(c,i+1);
            }
            else{
                int val=nums[i];
                if(m.contains(val)){
                    int b=m[val];
                    c=max(c, i-b);
                }
            }

            if(!m.contains(nums[i])){
                m[nums[i]]=i;
            }
        }
        

        
        return c;
    }
};