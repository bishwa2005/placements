/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void solve(TreeNode root,String path,List<String> ans){
        if(root==null) return;
        String node = String.valueOf(root.val);

        if(root.left==null && root.right==null){
            path+=node;
            ans.add(path);
            return;
        }

        solve(root.left,path+node+"->",ans);
        solve(root.right,path+node+"->",ans);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        solve(root,"",ans);
        return ans;
    }
}