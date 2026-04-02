from shared.python.data_structures import TreeNode


class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: list[int], rightChild: list[int]) -> bool:
        children = set(leftChild + rightChild) - {-1}
        roots = [i for i in range(n) if i not in children]
        if len(roots) != 1:
            return False
        root = roots[0]
        visited: set[int] = set()
        stack = [root]
        while stack:
            node = stack.pop()
            if node in visited:
                return False
            visited.add(node)
            if leftChild[node] != -1:
                stack.append(leftChild[node])
            if rightChild[node] != -1:
                stack.append(rightChild[node])
        return len(visited) == n
