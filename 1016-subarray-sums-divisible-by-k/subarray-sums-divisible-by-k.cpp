class Solution {
public:
    // int subarraysDivByK(vector<int>& nums, int k) {
    //     vector<int> a(nums.size(), 0);
    //     int count=0;

    //     unordered_map <int, int> m;

    //     a[0]=nums[0];
    //     for(int i=1; i<nums.size(); i++){
    //         a[i]=a[i-1]+nums[i];
    //     }

    //     for(int j=0; j<nums.size(); j++){
    //         if(a[j]%k==0){
    //             count++;
    //         }
    //         int val=a[j]%k;
    //         if(val<0){
    //             val=val+k;
    //         }
    //         if(m.contains(val)){
    //             count+=m[val];
    //         }
    //         m[val]++;
    //     }

    //     return count;

    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> a(nums.size(), 0);
        int count=0;

        unordered_map <int, int> m;

        a[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            a[i]=a[i-1]+nums[i];
        }
        m[0]=1;
        for(int j=0; j<nums.size(); j++){
            int val=a[j]%k;
            if(val<0){
                val=val+k;
            }
            if(m.contains(val)){
                count+=m[val];
            }
            m[val]++;
        }

        return count;
    }
};