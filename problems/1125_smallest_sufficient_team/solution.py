class Solution:
    def smallestSufficientTeam(self, req_skills: list[str], people: list[list[str]]) -> list[int]:
        n = len(req_skills)
        skill_idx = {s: i for i, s in enumerate(req_skills)}
        dp = {0: []}
        for i, person in enumerate(people):
            mask = 0
            for skill in person:
                if skill in skill_idx:
                    mask |= 1 << skill_idx[skill]
            for state, team in list(dp.items()):
                new_state = state | mask
                if new_state not in dp or len(dp[new_state]) > len(team) + 1:
                    dp[new_state] = team + [i]
        return dp[(1 << n) - 1]
