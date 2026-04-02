import java.util.*;

class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> c1 = new HashMap<>(), c2 = new HashMap<>();
        for (String w : words1) c1.merge(w, 1, Integer::sum);
        for (String w : words2) c2.merge(w, 1, Integer::sum);
        int count = 0;
        for (var e : c1.entrySet()) {
            if (e.getValue() == 1 && c2.getOrDefault(e.getKey(), 0) == 1) count++;
        }
        return count;
    }
}
