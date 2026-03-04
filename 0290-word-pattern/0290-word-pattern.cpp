class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        
        // split sentence into words
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (pattern.size() != words.size())
            return false;
        
        unordered_map<char, string> mp;
        unordered_set<string> used;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            if (mp.count(c)) {
                if (mp[c] != w)
                    return false;
            } 
            else {
                if (used.count(w))
                    return false;
                
                mp[c] = w;
                used.insert(w);
            }
        }
        
        return true;
    }
};