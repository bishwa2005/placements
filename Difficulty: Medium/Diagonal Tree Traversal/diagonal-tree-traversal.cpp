/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
};
*/

class Solution {
public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            while (node) {
                ans.push_back(node->data);

                if (node->left)
                    q.push(node->left);

                node = node->right;
            }
        }

        return ans;
    }
};