// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int c1=0;
//         int c2=0;
//         int e1=0;
//         int e2=0;
//         for(int i=0;i<nums.size(); i++){
//             if(c1==0 and nums[i]!=e2){
//                 e1=nums[i];
//                 c1++;
//             }
//             else if(c2==0 and nums[i]!=e1){
//                 e2=nums[i];
//                 c2++;
//             }
//             else if(nums[i]==e1){
//                 c1++;
//             }
//             else if(e2==nums[i]){
//                 c2++;
//             }
//             else{
//                 c1--;
//                 c2--;
//             }
//         }
//         int k=0;
//         int k1=0;
//         for(int i=0; i<nums.size(); i++){
//             if(e1==nums[i]){
//                 k++;
//             }
//             else if(e2==nums[i]){
//                 k1++;
//             }
//         }
//         int verify=(nums.size()/3);
//         bool y=false;
//         bool x=false;
//         if(verify<k){
//             x=true;
//         }
//         if(verify<k1){
//             y=true;
//         }

//         if(x==true and y==true){
//             return {e1, e2};
//         }
//         else if(x==true){
//             return {e1};
//         }
//         else if(y==true){
//             return {e2};
//         }
//         return {};
            
//     }
// };


// yeh ayush chake ka code hai

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1=NULL;
        int count1=0;
        int maj2=INT_MIN;
        int count2=0;

        vector<int> ans;

        for(int i =0 ; i<nums.size() ;i++){

            if(nums[i]==maj1 ){
                count1++;
            }
            else if(nums[i]==maj2){
                count2++;
            }
            else if(count1==0){
                maj1=nums[i];
                count1++;
            }
            else if(count2==0){
                maj2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }

        }
        // int freq1=0;
        // int freq2

        if(count(nums.begin(), nums.end(), maj1)> nums.size()/3){
            ans.push_back(maj1);
        }
        if(count(nums.begin(), nums.end(), maj2)> nums.size()/3){
            ans.push_back(maj2);
        }
        return ans;
    }
};