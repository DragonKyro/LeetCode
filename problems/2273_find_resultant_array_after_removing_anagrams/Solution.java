import java.util.*;

class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> result = new ArrayList<>();
        result.add(words[0]);
        for (int i = 1; i < words.length; i++) {
            char[] a = words[i].toCharArray(), b = words[i-1].toCharArray();
            Arrays.sort(a); Arrays.sort(b);
            if (!Arrays.equals(a, b)) result.add(words[i]);
        }
        return result;
    }
}
