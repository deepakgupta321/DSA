class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        s.push(arr.size()-1);
        
        int ans=0;

        vector<int> r(arr.size(), arr.size());
        vector<int> l(arr.size(), -1);

        for(int i=arr.size()-2; i>=0; i--){
            while(!s.empty() && arr[i]<=arr[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                r[i]=s.top();
            }

            s.push(i);
        }

        stack<int> s1;
        s1.push(0);

        for(int i=1; i<arr.size(); i++){
            while(!s1.empty() && arr[i]<=arr[s1.top()]){
                s1.pop();
            }
            if(!s1.empty()){
                l[i]=s1.top();
            }

            s1.push(i);
        }

        for(int i=0; i<arr.size(); i++){

            int x=arr[i] *(r[i]-l[i]-1);
            
            ans=max(ans,x);
        }

        return ans;



    }
};