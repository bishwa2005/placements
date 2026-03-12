class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;

        for(int i=0;i<n;i++){
            for(auto it : ingredients[i]){
                adj[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;

        for(auto it : supplies){
            q.push(it);
        }
        vector<string> ans;

        while(!q.empty()){
            string item = q.front();
            q.pop();

            for(auto &recipe : adj[item]){
                indegree[recipe]--;

                if(indegree[recipe] == 0){
                    ans.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};