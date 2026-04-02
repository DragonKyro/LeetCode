from typing import List


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = {}
        for word in words:
            node = trie
            for c in word:
                node = node.setdefault(c, {})
            node['#'] = word
        m, n = len(board), len(board[0])
        res = []
        def dfs(i, j, node):
            c = board[i][j]
            if c not in node:
                return
            nxt = node[c]
            if '#' in nxt:
                res.append(nxt.pop('#'))
            board[i][j] = '.'
            for di, dj in ((0,1),(0,-1),(1,0),(-1,0)):
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and board[ni][nj] != '.':
                    dfs(ni, nj, nxt)
            board[i][j] = c
            if not nxt:
                del node[c]
        for i in range(m):
            for j in range(n):
                dfs(i, j, trie)
        return res
