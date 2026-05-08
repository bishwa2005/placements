class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(),cmp);

        int arrows = 1;
        long long lastEnd = points[0][1];

        for(int i = 1; i < points.size(); i++) {

            // no overlap
            if(points[i][0] > lastEnd) {
                arrows++;
                lastEnd = points[i][1];
            }
        }

        return arrows;
    }
};