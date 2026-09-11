class Solution {
public:
    int totalNumbers(vector<int>& a) {
        unordered_set<int> st;
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a.size(); j++){
                for(int k=0; k<a.size(); k++){
                    if(i==j or j==k or i==k) continue;
                    int d=a[i]*100+a[j]*10+a[k];
                    if(d>=100 and d%2==0){
                        st.insert(d);
                    }
                }
            }
        }

        return st.size();
    }
};