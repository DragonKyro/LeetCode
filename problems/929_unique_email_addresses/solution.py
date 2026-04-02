from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique: set = set()
        for email in emails:
            local, domain = email.split('@')
            local = local.split('+')[0].replace('.', '')
            unique.add(local + '@' + domain)
        return len(unique)
