class Solution {
public:

    bool check(vector<int>& a, int m, int k, int mid){
        int c=0;
        int j=0;
        int n=0;

        while(j<a.size()){

            if(a[j]<=mid){
                c++;
                if(c==k){
                    n++;
                    c=0;
                }
            }
            else{
                c=0;
            }
            j++;

        }

        if(n>=m ){
            return true;
        }
        else{
            return false;
        }
    }



    int minDays(vector<int>& a, int m, int k) {
        if((long long)m*k> a.size()){
            return -1;
        }

        int i=1;
        int j=*max_element(a.begin(), a.end());
        int ans=1;

        while(i<=j){
            int mid=i+(j-i)/2;
        
            if(check(a, m, k , mid)){
                ans=mid;
                j=mid-1;
            }

            else{
                i=mid+1;
            }
        }

        return ans;
    }
};