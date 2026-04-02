import java.util.*;

class Solution {
    public String oddString(String[] words) {
        Map<String, List<String>> map = new HashMap<>();
        for (String w : words) {
            StringBuilder key = new StringBuilder();
            for (int i = 1; i < w.length(); i++) key.append(w.charAt(i) - w.charAt(i-1)).append(',');
            map.computeIfAbsent(key.toString(), k -> new ArrayList<>()).add(w);
        }
        for (var e : map.entrySet()) if (e.getValue().size() == 1) return e.getValue().get(0);
        return "";
    }
}
