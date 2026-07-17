class Solution {
public:
    int check(unordered_map<int, int> &m){
            int c=0;
            for(auto x: m){
                c=max(c,x.second);
            }
            return c;
        }


    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int i=0;
        int j=0;
        int result=0;


        while(j<nums.size()){
           
            if(nums[j]==1){
                m[nums[j]]++;
            }
               

            int len=j-i+1;

            //check kar rhe kitne min. hai jinhe flip ki need hai agr k se jyda ho gya we remove i;
            int d=len-check(m);
            while(i<nums.size() && d>k){
                
                if(nums[i]==1){
                    m[nums[i]]--;
                }
                i++;
                d=(j-i+1) - check(m);
            }

            result=max(result, j-i+1);
            j++;

        }

        return result;
    }
};