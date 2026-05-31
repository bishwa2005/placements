class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt=0;
        vector<string> v;

        for(auto w : words){
            set<char> st;
            for(auto c : w){
                st.insert(c);
            }
            string str="";
            for(auto i : st) str+=i;
            v.push_back(str);
        }

        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i]==v[j]) cnt++;
            }
        }

        return cnt;
    }
};