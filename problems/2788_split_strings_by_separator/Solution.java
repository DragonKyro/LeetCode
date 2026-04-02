import java.util.*;

class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> res = new ArrayList<>();
        for (String w : words) for (String p : w.split("\\" + separator)) if (!p.isEmpty()) res.add(p);
        return res;
    }
}
