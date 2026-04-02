from typing import List


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)
        if '0000' in dead:
            return -1
        queue = collections.deque([('0000', 0)])
        visited = {'0000'}
        while queue:
            state, turns = queue.popleft()
            if state == target:
                return turns
            for i in range(4):
                d = int(state[i])
                for delta in [-1, 1]:
                    nd = (d + delta) % 10
                    new_state = state[:i] + str(nd) + state[i+1:]
                    if new_state not in visited and new_state not in dead:
                        visited.add(new_state)
                        queue.append((new_state, turns + 1))
        return -1
