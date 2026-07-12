class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a=arr;
        sort(a.begin(), a.end());
       
        unordered_map<int, int> m;

        int d=0;

        for(int i=1; i<=a.size(); i++){
            m[a[i-1]]++;

            if(m[a[i-1]] >1){

                d++;

            }

            m[a[i-1]]=i-d;
            
        }

        for(int i=0; i<arr.size(); i++){
            arr[i]=m[arr[i]];
        }
        
        return arr;
    }
};