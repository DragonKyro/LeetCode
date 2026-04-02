from typing import List


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        parent = {}
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            parent[find(x)] = find(y)
        email_to_name = {}
        for account in accounts:
            name = account[0]
            for email in account[1:]:
                if email not in parent:
                    parent[email] = email
                email_to_name[email] = name
                union(email, account[1])
        groups = collections.defaultdict(list)
        for email in parent:
            groups[find(email)].append(email)
        return [[email_to_name[root]] + sorted(emails) for root, emails in groups.items()]
