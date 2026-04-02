import java.util.*;

class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        Set<Integer> hasIncoming = new HashSet<>();
        for (List<Integer> e : edges) hasIncoming.add(e.get(1));
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!hasIncoming.contains(i)) res.add(i);
        }
        return res;
    }
}
