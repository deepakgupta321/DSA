class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;

        while(i<j){

            int mid=i+(j-i)/2;
            bool y;
            if((j-mid)%2==0){
                y=true;
            }
            else{
                y=false;
            }

            // mid ke side wale element check kar rhe///...

            if(nums[mid]==nums[mid+1]){
                if(y){
                    i=mid+2;
                }
                else{
                    j=mid-1;
                }
            }
            else{  // mtlb aage wale ke equal nhi hai
                
                if(y==false){
                    i=mid+1;
                }
                else{
                    j=mid;
                }
            }
        }

        return nums[i];
    }
};