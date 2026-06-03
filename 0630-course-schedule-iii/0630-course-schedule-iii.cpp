class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(), cmp);

        priority_queue<int> pq;
        int time = 0;

        for(auto &it : courses){

            if(time + it[0] <= it[1]){
                pq.push(it[0]);
                time += it[0];
            }
            else if(!pq.empty() && pq.top() > it[0]){
                time -= pq.top();
                pq.pop();

                time += it[0];
                pq.push(it[0]);
            }
        }

        return pq.size();
    }
};