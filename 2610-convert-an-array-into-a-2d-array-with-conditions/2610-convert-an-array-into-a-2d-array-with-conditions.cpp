#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> ans;

        int maxi=INT_MIN;

        for(auto& [key,val] : mp){
            maxi=max(maxi,val);
        }

        while(maxi--){
            vector<int> vec;
            
            for (auto& [key, val] : mp) {
                if(mp[key]>0){

                    vec.push_back(key);
                    mp[key]--;
                }
                // if (val == 0) {
                //     mp.erase(key);
                // }
            }

            

            ans.push_back(vec);
        }

        return ans;
    }
};
