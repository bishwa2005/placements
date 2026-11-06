class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1]; // Sort logs by request time
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // 1. Sort logs by timestamp
        sort(logs.begin(), logs.end(), cmp);
        
        // 2. Store queries with their original indices and sort them by time
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < m; ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // 3. Sliding Window variables
        vector<int> serverCounts(n + 1, 0); // Tracks request count for each server id (1 to n)
        int uniqueActiveServers = 0;
        int left = 0;
        int right = 0;
        
        // 4. Process each sorted query
        for (const auto& q : sortedQueries) {
            int qTime = q.first;
            int qIdx = q.second;
            int minTime = qTime - x;
            int maxTime = qTime;
            
            // Expand the window: Add logs that fall into the range (<= maxTime)
            while (right < logs.size() && logs[right][1] <= maxTime) {
                int serverId = logs[right][0];
                if (serverCounts[serverId] == 0) {
                    uniqueActiveServers++;
                }
                serverCounts[serverId]++;
                right++;
            }
            
            // Shrink the window: Remove logs that are too old (< minTime)
            while (left < logs.size() && logs[left][1] < minTime) {
                int serverId = logs[left][0];
                serverCounts[serverId]--;
                if (serverCounts[serverId] == 0) {
                    uniqueActiveServers--;
                }
                left++;
            }
            
            // The remaining servers had 0 requests
            ans[qIdx] = n - uniqueActiveServers;
        }
        
        return ans;
    }
};
