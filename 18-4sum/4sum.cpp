class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        
        vector<vector<int>> ans;
        int n=a.size();
        sort(a.begin(), a.end());
        for(int i=0; i<n-3; i++){
            
            if(i>0 && a[i]==a[i-1]) continue;
            int j=i+1;
            
            for(int k=j; k<n-2; k++){
                if(k>j && a[k]==a[k-1]) continue;
                int s=k+1;
                int e=n-1;
                
                while(s<e){
                    long long sum=(1ll)*a[i]+a[k]+a[s]+a[e];
                    if(sum==target){
                        ans.push_back({a[i],a[k],a[s],a[e]});
                        
                        while(s<e && a[s]==a[s+1]){
                            s++;
                        }
                        s++;
                        
                        while(e>s && a[e-1]==a[e]){
                            e--;
                        }
                        e--;
                    }
                    
                    if(sum>target){
                        e--;
                    }
                    if(sum<target){
                        s++;
                    }
                }
            }
        }
        
        return ans;
    }
};