class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        // Min heap
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        set<pair<int,int>> vis;

        pq.push({nums1[0] + nums2[0], {0,0}});
        vis.insert({0,0});

        vector<vector<int>> ans;

        while(!pq.empty() && ans.size() < k){
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            // push actual values
            ans.push_back({nums1[i], nums2[j]});

            // next pair (i+1, j)
            if(i + 1 < n && vis.count({i+1, j}) == 0){
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                vis.insert({i+1, j});
            }

            // next pair (i, j+1)
            if(j + 1 < m && vis.count({i, j+1}) == 0){
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                vis.insert({i, j+1});
            }
        }

        return ans;
    }
};