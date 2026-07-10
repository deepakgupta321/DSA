class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st1;
        vector<int> vl(arr.size(),-1);

        st1.push(0);

        for(int i=1; i<arr.size(); i++){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                st1.pop();
            }

            if(!st1.empty()){
                vl[i]=st1.top();
            }
            st1.push(i);
        }

        stack<int> s;
        vector<int> vr(arr.size(), arr.size());
        s.push(arr.size()-1);

        for(int i=arr.size()-2; i>=0; i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }

            if(!s.empty()){
                vr[i]=s.top();
            }

            s.push(i);
        }


        int mod=1e9+7;
        long long sum=0;

        for(int i=0; i<arr.size(); i++){
            int left=i-vl[i];
            int right=vr[i]-i;
            long long totalway=(left*right)%mod;
            sum+=(arr[i]*totalway)%mod;
        }
        

        return sum%mod;


    }
};