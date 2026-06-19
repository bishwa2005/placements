// User function Template for Java//User function Template for Java
class Solution {
    void solve(int idx,int[] arr,int sub,ArrayList<Integer> ans){
        if(idx==arr.length){
            ans.add(sub);
            return;
        }
        
        sub+=arr[idx];
        solve(idx+1,arr,sub,ans);
        sub-=arr[idx];
        solve(idx+1,arr,sub,ans);
    }
    
    public ArrayList<Integer> subsetSums(int[] arr) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        int sub=0;
        
        solve(0,arr,sub,ans);
        
        return ans;
        
    }
}