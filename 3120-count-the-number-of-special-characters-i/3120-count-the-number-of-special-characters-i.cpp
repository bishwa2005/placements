class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;
        int cnt=0;
        for(auto it : word){
            if(islower(it) && !st.count(it)){
                if(st.count(toupper(it))) cnt++;
            }
            if(isupper(it) && !st.count(it)){
                if(st.count(tolower(it))) cnt++;
            }
            st.insert(it);
        }
        return cnt;
    }
};