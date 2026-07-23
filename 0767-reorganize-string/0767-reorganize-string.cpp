class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;

        for(char ch : s)
            mp[ch]++;

        int freq = 0;
        char mostFreq;

        for(auto &[ch,cnt] : mp){
            if(cnt > freq){
                freq = cnt;
                mostFreq = ch;
            }
        }

        if(freq > (s.size() + 1) / 2)
            return "";

        vector<char> ans(s.size());

        int idx = 0;

        while(mp[mostFreq] > 0){
            ans[idx] = mostFreq;
            idx += 2;
            mp[mostFreq]--;
        }

        for(auto &[ch,cnt] : mp){
            while(cnt > 0){
                if(idx >= s.size())
                    idx = 1;

                ans[idx] = ch;
                idx += 2;
                cnt--;
            }
        }

        return string(ans.begin(), ans.end());
    }
};