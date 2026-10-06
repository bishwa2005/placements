class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        int curr=0;

        for(char c : s){
            c=c-'0';
            ans+=min(abs(curr-c),9-abs(curr-c)+1);
            curr=c;
        }

        return ans;
    }
};