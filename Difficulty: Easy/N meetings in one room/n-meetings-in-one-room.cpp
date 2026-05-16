class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> meet;
        
        for(int i=0;i<start.size();i++){
            meet.push_back({start[i],end[i]});
        }
        
        sort(meet.begin(),meet.end(),cmp);
        int n=1;
        int end_t = meet[0].second;
        for(int i=1;i<meet.size();i++){
            if(meet[i].first > end_t){
                n++;
                end_t=meet[i].second;
            }
        }
        
        return n;
        
    }
};