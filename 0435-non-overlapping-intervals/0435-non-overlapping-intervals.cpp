class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
        int n=intervals.size();

        int last_end=intervals[0][1];

        for(int i=1;i<n;i++){
            if(last_end > intervals[i][0]) cnt++;
            else{
                last_end=intervals[i][1];
            }
        }

        return cnt;
    }
};