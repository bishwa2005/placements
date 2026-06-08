class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> s;
        vector<int> l;
        int p=0;

        for(int i : nums){
            if(i==pivot) p++;
            else if(i<pivot) s.push_back(i);
            else l.push_back(i);
        }

        while(p--){
            s.push_back(pivot);
        }

        for(int i : l){

            s.push_back(i);
        }

        return s;
    }
};