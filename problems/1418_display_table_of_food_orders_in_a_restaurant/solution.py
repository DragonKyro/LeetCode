from typing import List


class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        from collections import defaultdict
        tables = defaultdict(lambda: defaultdict(int))
        foods = set()
        for _, table, food in orders:
            tables[int(table)][food] += 1
            foods.add(food)
        sorted_foods = sorted(foods)
        res = [['Table'] + sorted_foods]
        for table in sorted(tables.keys()):
            row = [str(table)]
            for food in sorted_foods:
                row.append(str(tables[table][food]))
            res.append(row)
        return res
