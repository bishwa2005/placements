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
        if(!root) return {};
        
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(q.size()){
            auto [node,idx] = q.front();
            q.pop();
            
            if(!mp.count(idx)) mp[idx]=node->data;
            
            if(node->left) q.push({node->left,idx-1});
            if(node->right) q.push({node->right,idx+1});
        }
        
        vector<int> ans;
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};