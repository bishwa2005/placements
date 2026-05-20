/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int,int> mp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(q.size()){
            auto [node,idx] = q.front();
            q.pop();
            
            mp[idx]=node->data;
            
            if(node->left) q.push({node->left,idx-1});
            if(node->right) q.push({node->right,idx+1});
        }
        
        vector<int> ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};