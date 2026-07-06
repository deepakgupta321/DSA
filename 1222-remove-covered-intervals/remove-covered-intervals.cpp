class Solution {
public:
    static bool cmd(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
        
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmd);
        vector<vector<int>> a;
        a.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            int x=a.size()-1;
            if(a[x][0]<=intervals[i][0]  and  a[x][1]>=intervals[i][1]){
                //nothing
            }
            else{
                a.push_back(intervals[i]);
            }
        }
        return a.size();
    }
};