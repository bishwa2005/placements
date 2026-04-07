class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        vector<int> paper_counts(n + 1, 0);
        
        // Count frequencies
        for (int c : citations) {
            paper_counts[min(n, c)]++;
        }
        
        int h = n;
        int papers = paper_counts[n];
        
        // Find h-index
        while (papers < h) {
            h--;
            papers += paper_counts[h];
        }
        
        return h;
    }
};