from typing import List, Optional
from shared.python.data_structures import TreeNode


class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        from collections import Counter
        count = Counter()
        
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            s = node.val + dfs(node.left) + dfs(node.right)
            count[s] += 1
            return s
        
        dfs(root)
        max_freq = max(count.values())
        return [s for s, freq in count.items() if freq == max_freq]
