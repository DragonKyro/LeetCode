import java.util.*;

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> ban = new HashSet<>(Arrays.asList(banned));
        Map<String, Integer> count = new HashMap<>();
        String[] words = paragraph.toLowerCase().split("[^a-z]+");
        for (String w : words) {
            if (!w.isEmpty() && !ban.contains(w))
                count.merge(w, 1, Integer::sum);
        }
        return Collections.max(count.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}
