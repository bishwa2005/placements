class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st;
        int cnt=0;
        for(auto i : password){
            if(!st.count(i)){
                st.insert(i);
                if(islower(i)) cnt+=1;
                else if(isupper(i)) cnt+=2;
                else if(isdigit(i)) cnt+=3;
                else if(ispunct(i)) cnt+=5;
            }
        }

        return cnt;
    }
};