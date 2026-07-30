class Solution {
public: 

    static bool cmd(int x, int y){
        return x>y;
    }
    int minimumPushes(string s) {
        
        vector<int> v(26,0);

        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
        }

        sort(v.begin(), v.end(), cmd);
        int sum=0;

        for(int i=0; i<26; i++){
            while(i<8){
                sum+=v[i];
                i++;
            }
            while(i<16){
                sum=sum+v[i]*2;
                i++;
            }
            while(i<24){
                sum=sum+v[i]*3;
                i++;
            }
            while(i<26){
                sum=sum+v[i]*4;
                i++;
            }
        }

        return sum;

    }
};