class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        white_count = blocks[:k].count('W')
        min_ops = white_count
        for i in range(k, len(blocks)):
            white_count += (blocks[i] == 'W') - (blocks[i - k] == 'W')
            min_ops = min(min_ops, white_count)
        return min_ops
