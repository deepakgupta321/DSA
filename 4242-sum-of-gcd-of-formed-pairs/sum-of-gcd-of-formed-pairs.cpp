class Solution {
public:
    int gcd(int a, int b){
        if(b==0){
            return a;
        }

        return gcd(b, a%b);
    }


    long long gcdSum(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);

        vector<int> gcd1;
        gcd1.push_back(v[0]);


        for(int i=1; i<nums.size(); i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
            }
            else{
                v.push_back(v.back());
            }

            gcd1.push_back(gcd(nums[i], v[i]));

        }
         
        sort(gcd1.begin(), gcd1.end());
        long long sum=0;

        int i=0;
        int j=gcd1.size()-1;

        while(i<j){
            sum+=gcd(gcd1[i], gcd1[j]);
            i++;
            j--;
        }

        return sum;





    }
};