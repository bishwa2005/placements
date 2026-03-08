class Solution {
public:
    
    string ans = "";
    unordered_set<string> st;
    
    void solve(string curr, int n){
        
        if(curr.size() == n){
            if(st.find(curr) == st.end()){
                ans = curr;
            }
            return;
        }
        
        if(ans != "") return;
        
        solve(curr + "0", n);
        solve(curr + "1", n);
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        for(auto s : nums)
            st.insert(s);
        
        int n = nums.size();
        
        solve("", n);
        
        return ans;
    }
};