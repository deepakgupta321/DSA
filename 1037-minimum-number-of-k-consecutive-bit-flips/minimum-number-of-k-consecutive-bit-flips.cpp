class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<int> dq;
        int result=0;

        int ff=0;
        int j=0;

        while(j<nums.size()){

            if(dq.size()==k){
                if(dq.front()==1){
                    ff=ff-dq.front();
                }
                dq.pop_front();
            
            }

            if(nums[j]==0 && ff%2==0){
                ff++;
                result++;
                dq.push_back(1);
                if(j+k>nums.size()){
                    return -1;
                }
            }
            else if(nums[j]==1 && ff%2!=0){
                ff++;
                result++;
                dq.push_back(1);
                if(j+k>nums.size()){
                    return -1;
                }
            }
            else{
                dq.push_back(0);
            }
            j++;
        }

        

        return result;

        
    }
};