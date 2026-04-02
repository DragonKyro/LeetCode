class Solution:
    def getImportance(self, employees: list, id: int) -> int:
        emp_map = {e.id: e for e in employees}
        def dfs(eid):
            e = emp_map[eid]
            return e.importance + sum(dfs(sub) for sub in e.subordinates)
        return dfs(id)
