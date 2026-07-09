class Solution {
public:
    int trap(vector<int>& height) {

        int size= height.size();
        vector<int> l(height.size());
        vector<int> r(height.size());
        
        l[0]=height[0];
        r[size-1]=height[size-1];

        for(int i=1; i<size; i++){
            l[i]=max(height[i], l[i-1]);
        }

        for(int i=size-2; i>=0; i--){
            r[i]=max(height[i], r[i+1]);
        }

        int ans=0;
        for(int i=0; i<size; i++){
            ans+= min(l[i], r[i])-height[i];
        }

        return ans;

        
    }
};