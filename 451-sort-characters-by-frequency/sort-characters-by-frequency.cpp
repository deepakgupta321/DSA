class Solution {

public:
    static bool cmd(pair<char,int> a, pair<char,int> b){
        return a.second>b.second;
    }

    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }

        vector<pair<char,int>> v;
        for(auto x: m){
            v.push_back(x);
        }

        sort(v.begin(), v.end(), cmd);
        string ans="";

        for(int i=0; i<v.size(); i++){
            ans.append(v[i].second, v[i].first);
        }
        return ans;
    }
};