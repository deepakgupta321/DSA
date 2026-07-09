class Solution {
public:
    int trap(vector<int>& height) {

        // int size= height.size();
        // vector<int> l(height.size());
        // vector<int> r(height.size());
        
        // l[0]=height[0];
        // r[size-1]=height[size-1];

        // for(int i=1; i<size; i++){
        //     l[i]=max(height[i], l[i-1]);
        // }

        // for(int i=size-2; i>=0; i--){
        //     r[i]=max(height[i], r[i+1]);
        // }

        // int ans=0;
        // for(int i=0; i<size; i++){
        //     ans+= min(l[i], r[i])-height[i];
        // }

        // return ans;
         
        int size=height.size();
        int i=0;
        int j=size-1;
        int left=0;
        int right=0;
        int ans=0;
        while(i<=j){
            left=max(left,height[i]);
            right=max(right,height[j]);
            if(left<right){
                ans+=left-height[i];
                i++;
            }
            else{
                ans+=right-height[j];
                j--;
            }
        }
        return ans;
        
    }
};