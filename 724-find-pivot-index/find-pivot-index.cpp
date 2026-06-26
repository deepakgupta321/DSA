class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // using prefix and suffix vector
        // ismai extra memory lag gyi ab without memory karega

        // vector<int> prefix(nums.size(),0);
        // vector<int> suffix(nums.size(),0);
        
        
        // for(int i=1; i<nums.size(); i++){
        //     prefix[i]=prefix[i-1]+ nums[i-1];
        // }
        
        // for(int i=nums.size()-2; i>=0; i--){
        //     suffix[i]=suffix[i+1]+nums[i+1];
        // }


        // for(int i=0; i<prefix.size(); i++){
        //     if(prefix[i]==suffix[i]){
        //         return i;
        //     }
        // }

        // return -1;

        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
        }

        int temp=0;
        for(int i=0; i<nums.size(); i++){
            if(i>0){
                temp=nums[i-1]+temp;
            }
            else{
                temp=0;
            }
            

            int x=sum-(temp+nums[i]);

            if(temp==x){
                return i;
            }
        }

        return -1;

    }
};