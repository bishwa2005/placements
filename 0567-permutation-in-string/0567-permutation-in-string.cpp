class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        vector<int> f1(26, 0);
        for(int k = 0; k < n; k++){
            f1[s1[k] - 'a']++;
        }

        for(int i = 0; i <= m - n; i++){
            vector<int> f2(26, 0);
            
            for(int j = 0; j < n; j++){
                f2[s2[i + j] - 'a']++;
            }

            if(f1 == f2) return true;
        }

        return false;
    }
};