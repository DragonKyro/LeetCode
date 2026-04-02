class Solution:
    def findDuplicate(self, paths: list[str]) -> list[list[str]]:
        from collections import defaultdict
        content_map = defaultdict(list)
        for path in paths:
            parts = path.split()
            directory = parts[0]
            for file in parts[1:]:
                idx = file.index('(')
                filename = file[:idx]
                content = file[idx + 1:-1]
                content_map[content].append(directory + '/' + filename)
        return [v for v in content_map.values() if len(v) > 1]
