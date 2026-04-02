class Solution:
    def twoEggDrop(self, n: int) -> int:
        m = 0
        k = 0
        while m < n:
            k += 1
            m += k
        return k
