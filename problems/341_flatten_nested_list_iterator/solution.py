class NestedIterator:
    def __init__(self, nestedList: list):
        self.stack = []
        self._flatten(nestedList)
        self.idx = 0

    def _flatten(self, nested):
        for item in nested:
            if item.isInteger():
                self.stack.append(item.getInteger())
            else:
                self._flatten(item.getList())

    def next(self) -> int:
        val = self.stack[self.idx]
        self.idx += 1
        return val

    def hasNext(self) -> bool:
        return self.idx < len(self.stack)
