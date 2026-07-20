class Solution {
public:
    bool check(vector<int> &piles, int mid, int h){ 
        int c=0;
        for(int i=0; i<piles.size(); i++){
            c+=piles[i]/mid;

            if(piles[i]%mid!=0){
                c++;
            }

            if(c>h){
                return false;
            }

        }
        return true; 
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int r=*max_element(piles.begin(), piles.end());
        int ans=1;

        int i=1;
        int j=r;
        while(i<=j){
            int mid=i+(j-i)/2;
            
            bool t=check(piles,mid , h);
            if(t==true){
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