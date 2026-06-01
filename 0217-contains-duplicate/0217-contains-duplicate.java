import java.util.HashSet;

class Solution { 
    public boolean containsDuplicate(int[] nums) { 
        // Use Integer wrapper class instead of primitive int
        HashSet<Integer> st = new HashSet<Integer>(); 
        
        for (int i : nums) { 
            if (st.contains(i)) {
                return true; 
            }
            st.add(i); 
        } 
        return false; 
    } 
}
