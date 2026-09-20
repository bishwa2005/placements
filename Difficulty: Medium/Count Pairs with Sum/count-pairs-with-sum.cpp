
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int n=arr.size();
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            int r=target-arr[i];
            if(mp.find(r)!=mp.end()){
                cnt+=mp[r];
            }
            mp[arr[i]]++;
        }
        return cnt;
    }
};

