class Solution:
    def isPossibleDivide(self, nums: list[int], k: int) -> bool:
        from collections import Counter
        cnt = Counter(nums)
        for num in sorted(cnt):
            if cnt[num] > 0:
                freq = cnt[num]
                for i in range(num, num + k):
                    if cnt[i] < freq:
                        return False
                    cnt[i] -= freq
        return True
