class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        int i=0;
        int j=0;
        while(j<nums.size()){
            while(!q.empty() && q.back()<nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);

            
            if(q.empty()){
                q.push_front(nums[j]);
            }


            if(k==j-i+1){
                ans.push_back(q.front());
                if(q.front()==nums[i]){
                    q.pop_front();
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};