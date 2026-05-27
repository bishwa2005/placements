class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest=0;

        for(int i : st){
            if(!st.count(i-1)){
                int curr=1;
                int ele=i;
                while(st.count(ele+1)){
                    ele+=1;
                    curr+=1;
                }
                longest=max(longest,curr);
            }
        }

        return longest;
    }
};