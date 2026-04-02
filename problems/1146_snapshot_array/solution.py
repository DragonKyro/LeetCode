class SnapshotArray:
    def __init__(self, length: int):
        self.snaps = [[[0, 0]] for _ in range(length)]
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
        if self.snaps[index][-1][0] == self.snap_id:
            self.snaps[index][-1][1] = val
        else:
            self.snaps[index].append([self.snap_id, val])

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        import bisect
        arr = self.snaps[index]
        i = bisect.bisect_right(arr, [snap_id, float('inf')]) - 1
        return arr[i][1]
