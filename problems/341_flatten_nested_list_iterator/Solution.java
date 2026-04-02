import java.util.*;

public class NestedIterator implements Iterator<Integer> {
    private List<Integer> list = new ArrayList<>();
    private int idx = 0;
    public NestedIterator(List<NestedInteger> nestedList) {
        flatten(nestedList);
    }
    private void flatten(List<NestedInteger> nestedList) {
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) list.add(ni.getInteger());
            else flatten(ni.getList());
        }
    }
    @Override
    public Integer next() { return list.get(idx++); }
    @Override
    public boolean hasNext() { return idx < list.size(); }
}
