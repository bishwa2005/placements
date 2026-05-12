class Solution {
public:
    bool ispossible(vector<vector<int>>& tasks,int mid){
        for(auto &it : tasks){
            int actual=it[0];
            int mini=it[1];

            if(mid<mini) return false;

            mid-=actual;
        }
        return true;
    }


    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(),tasks.end(),cmp);

        int l=0;
        int r=1e9;
        int result;
        while(l<=r){
            int mid = l+(r-l)/2;

            if(ispossible(tasks,mid)){
                r=mid-1;
                result=mid;
            }
            else{
                l=mid+1;
            }
        }

        return result;
    }
};