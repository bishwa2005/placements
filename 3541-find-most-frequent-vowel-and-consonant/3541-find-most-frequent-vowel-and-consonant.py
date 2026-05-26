class Solution:
    def maxFreqSum(self, s: str) -> int:
        vl = 0
        cn = 0

        v_mp = {}
        c_mp = {}

        for ch in s:
            if ch in "aeiou":
                v_mp[ch] = v_mp.get(ch, 0) + 1
            else:
                c_mp[ch] = c_mp.get(ch, 0) + 1

        for v in v_mp.values():
            vl = max(vl, v)

        for c in c_mp.values():
            cn = max(cn, c)

        return vl + cn