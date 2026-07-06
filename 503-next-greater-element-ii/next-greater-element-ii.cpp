class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> v;
        for(int i=nums.size()-1; i>=0 ; i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }

            if(s.empty()){
                bool u=false;
                int j=0;
                while(j<i){
                    if(nums[j]>nums[i]){
                        u=true;
                        s.push(nums[j]);
                        v.push_back(s.top());
                        break;
                    }
                    s.push(nums[j]);
                    j++;
                }
                if(u==false)
                   v.push_back(-1);
                s.push(nums[i]);  
                
            }
            else{
                v.push_back(s.top());
                s.push(nums[i]);
            }
            
              
        }
        reverse(v.begin(), v.end());
        return v;
    }
};