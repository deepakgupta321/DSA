class Solution {
public:
    int hIndex(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int n=arr.size()-1;
        int ans=0;

        

        while(i<=j){
            int mid=i+(j-i)/2;
            
                
            if(arr[mid]<=n-mid){
        
                ans=n-mid;
                i=mid+1;
            }

            else{
                
                ans=n-mid+1;
                j=mid-1;
            }
        }
        
        

        return ans;
        
    }
};