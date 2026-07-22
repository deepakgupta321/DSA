class Solution {
public:
    bool check(vector<int>& v){
        for(int i=0; i<256; i++){
            if(v[i]>1){
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {

        
        // brute case we check each thing from 0 if find duplicate break ; and store max value;


        // int l=INT_MIN;
        // if(s.size()==0){
        //     return 0;
        // }
        // for(int i=0; i<s.size(); i++){
        //     vector<int> hash(256,0);
        //     int y=0;
        //     for(int j=i; j<s.size(); j++){
            
        //     if(hash[s[j]]==0){
        //         y++;
        //         hash[s[j]]++;
        //         l=max(y,l);
        //     }
        //     else{
        //         break;
        //     }
        //     }
        // } return l;
          //  yeh without map using  kara hai;


        // int len=INT_MIN;  
        // vector<int> v(256,0);
        // if(s.size()==0){
        //     return 0;
        // }
        //     int l=0;
        //     int r=0;
        //     while(r<s.size()){
        //         if(v[s[r]]==0){
        //             v[s[r]]=1;
        //             len=max(len,(r-l+1));
        //             r++;
        //         }
        //         else{
        //             while(v[s[r]]){
        //                 v[s[l]]=0;
        //                 l++;
        //             }
        //         }
        //     } return len;

    //     if(s.size()==0){
    //         return 0;
    //     }
    //         unordered_map<char, int> m;
    //         int len=INT_MIN;
    //         int low=0;
    //         int high=0;
    //         while(high<s.size()){
    //             while( high<s.size() and m[s[high]]==0 ){
    //                 m[s[high]]++;
    //                 len=max(len,high-low+1);
    //                 high++;
    //             }


    //             while(low <s.size() and m[s[high]]){
    //                 m[s[low]]--;
    //                 if(m[s[low]]==0){
    //                     m.erase(s[low]);
    //                 }
    //                 low++;
    //             }





    //         }

    // return len;
         
        if(s.size()==0){
            return 0;
        }

        int i=0;
        int j=0;
        vector<int> v(256,0);
        int ans=1;

        while(j<s.size()){
            v[s[j]]++;

            while(i<s.size()  && check(v)){
                v[s[i]]--;
                i++;

            }

            ans=max(ans, j-i+1);
            j++;
        }
        

        return ans;

          
    }
};