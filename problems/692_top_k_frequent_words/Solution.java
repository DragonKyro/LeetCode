import java.util.*;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap<>();
        for (String w : words) count.merge(w, 1, Integer::sum);
        List<String> keys = new ArrayList<>(count.keySet());
        keys.sort((a, b) -> count.get(a).equals(count.get(b)) ? a.compareTo(b) : count.get(b) - count.get(a));
        return keys.subList(0, k);
    }
}
