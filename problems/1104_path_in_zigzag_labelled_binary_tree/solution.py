class Solution:
    def pathInZigZagTree(self, label: int) -> list[int]:
        result = []
        node = label
        while node >= 1:
            result.append(node)
            level = node.bit_length() - 1
            level_max = (1 << (level + 1)) - 1
            level_min = 1 << level
            parent_label = (level_max + level_min - node) // 2
            node = parent_label
        return result[::-1]
