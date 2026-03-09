class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;

        if(root) q.push(root);

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                Node* nd = q.front();
                q.pop();

                if(sz) nd->next = q.front();

                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
        }

        return root;
    }
};