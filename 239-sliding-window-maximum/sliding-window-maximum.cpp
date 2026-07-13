class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        int i=0;
        int j=0;
        while(j<nums.size()){
            while(!dq.empty() && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);


            if(dq.empty()){
                dq.push_front(nums[j]);
            }


            if(k==j-i+1){
                ans.push_back(dq.front());
                if(dq.front()==nums[i]){
                    dq.pop_front();
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};