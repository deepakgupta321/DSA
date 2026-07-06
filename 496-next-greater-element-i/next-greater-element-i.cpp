class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        v.push_back(-1);
        stack<int> s;
        s.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2; i>=0; i--){
            if(s.top()>nums2[i]){
                v.push_back(s.top());
                s.push(nums2[i]);
            }
            else{
                while(!s.empty()){
                    s.pop();
                    if(!s.empty() and s.top()>nums2[i]){
                        v.push_back(s.top());
                        break;
                    }
                }
                if(s.empty())
                   v.push_back(-1);
                s.push(nums2[i]);
            }
        }
        reverse(v.begin(), v.end());
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int x=nums1[i];
            int j=0;
            while(j<nums2.size()){
                if(x==nums2[j]){
                    ans.push_back(v[j]);
                    j++;
                    break;
                }
                j++;
            }
        }
        return ans;

    }
};