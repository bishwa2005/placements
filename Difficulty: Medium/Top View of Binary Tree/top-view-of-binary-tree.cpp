/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,int> mp;
        
        queue<pair<int,Node*>> q;
        q.push({0,root});
        
        while(q.size()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                auto node = q.front().second;
                int idx = q.front().first;
                q.pop();
                
                if(!mp.count(idx))
                    mp[idx]=node->data;
                
                if(node->left) q.push({idx-1,node->left});
                if(node->right) q.push({idx+1,node->right});
            }
        }
        
        vector<int> ans;
        
        for(auto &[key,val] : mp){
            ans.push_back(val);
        }
        
        return ans;
        
    }
};