class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<vector<int>> st;  //{type,color,groupSize}

        for(int i=0;i<types.size();i++){
            if(st.size() && st.top()[0]==types[i] && st.top()[1]==colors[i]){
                // if we encounter the same element increase the groupsize
                auto t = st.top();
                t[2]+=1;
                st.pop();
                st.push(t);
            }
            else{
                st.push({types[i],colors[i],1});
            }
            if(st.top()[2]==groupSize[st.top()[0]]) st.pop();
        }

        return !st.size();
    }
};