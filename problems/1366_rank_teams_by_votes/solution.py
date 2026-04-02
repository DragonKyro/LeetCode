class Solution:
    def rankTeams(self, votes: list[str]) -> str:
        from collections import defaultdict
        n = len(votes[0])
        count: dict[str, list[int]] = defaultdict(lambda: [0] * n)
        for vote in votes:
            for i, c in enumerate(vote):
                count[c][i] += 1
        teams = list(votes[0])
        teams.sort(key=lambda c: ([-x for x in count[c]], c))
        return ''.join(teams)
