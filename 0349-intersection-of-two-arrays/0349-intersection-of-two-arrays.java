class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> seen = new HashSet<Integer>();
        HashSet<Integer> check = new HashSet<Integer>();
        
        for(int i : nums1){
            check.add(i);
        }

        var ans = new ArrayList<Integer>();

        for(int i : nums2){
            if(!seen.contains(i) && check.contains(i)){
                seen.add(i);
                ans.add(i);
            }
        }

        int[] result = new int[ans.size()];

        for (int i = 0; i < ans.size(); i++) {

            result[i] = ans.get(i);
        }

        return result;
    }
}