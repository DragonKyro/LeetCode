class Solution:
    def rearrangeBarcodes(self, barcodes: list[int]) -> list[int]:
        from collections import Counter
        count = Counter(barcodes)
        sorted_items = sorted(count.items(), key=lambda x: -x[1])
        result = [0] * len(barcodes)
        idx = 0
        for val, cnt in sorted_items:
            for _ in range(cnt):
                result[idx] = val
                idx += 2
                if idx >= len(barcodes):
                    idx = 1
        return result
