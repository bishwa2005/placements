class Solution:
    def maxDistinct(self, s: str) -> int:
        st = set()

        for ch in s:
            st.add(ch)

        return len(st)