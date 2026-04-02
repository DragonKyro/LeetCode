class Solution:
    def canReach(self, arr: list[int], start: int) -> bool:
        n = len(arr)
        visited = set()
        stack = [start]
        while stack:
            i = stack.pop()
            if arr[i] == 0:
                return True
            if i in visited:
                continue
            visited.add(i)
            if i + arr[i] < n:
                stack.append(i + arr[i])
            if i - arr[i] >= 0:
                stack.append(i - arr[i])
        return False
