class Solution {
public:
    int check(string &w1, string &w2){
        int cnt = 0;
        for(int i = 0; i < w1.size(); i++){
            if(w1[i] != w2[i]){
                cnt++;
                if(cnt > 2) return cnt; // early break (optimization)
            }
        }
        return cnt;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(string &q : queries){
            for(string &d : dictionary){
                if(check(q, d) <= 2){
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
    }
};