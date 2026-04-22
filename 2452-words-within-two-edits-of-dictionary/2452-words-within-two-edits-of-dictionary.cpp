class Solution {
public:
    int check(string &w1,string &w2){
        int n = w1.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(w1[i]!=w2[i]) cnt++;
        }
        return cnt;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();

        int i=0,j=0;

        vector<string> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string w1 = queries[i];
                string w2 = dictionary[j];

                if(check(w1,w2)>2) continue;
                else{
                    ans.push_back(w1);
                    break;
                }
            }
        }

        while(i<n && j<m){
            
        }

        return ans;
    }
};