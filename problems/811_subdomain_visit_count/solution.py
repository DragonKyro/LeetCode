from typing import List


class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        counts = {}
        for cp in cpdomains:
            count, domain = cp.split()
            count = int(count)
            parts = domain.split('.')
            for i in range(len(parts)):
                sub = '.'.join(parts[i:])
                counts[sub] = counts.get(sub, 0) + count
        return [f"{v} {k}" for k, v in counts.items()]
