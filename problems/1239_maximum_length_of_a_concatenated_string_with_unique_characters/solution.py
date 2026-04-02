class Solution:
    def maxLength(self, arr: list[str]) -> int:
        dp = [set()]
        for s in arr:
            if len(set(s)) != len(s):
                continue
            cs = set(s)
            new_dp = []
            for existing in dp:
                if cs & existing:
                    continue
                new_dp.append(cs | existing)
            dp.extend(new_dp)
        return max(len(x) for x in dp)
