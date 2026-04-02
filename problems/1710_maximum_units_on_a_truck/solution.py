from typing import List


class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: -x[1])
        units = 0
        for boxes, unit in boxTypes:
            take = min(boxes, truckSize)
            units += take * unit
            truckSize -= take
            if truckSize == 0:
                break
        return units
