import java.util.*;

class Solution {
    public String frequencySort(String s) {
        int[] count = new int[128];
        for (char c : s.toCharArray()) count[c]++;
        List<Character> chars = new ArrayList<>();
        for (int i = 0; i < 128; i++) if (count[i] > 0) chars.add((char) i);
        chars.sort((a, b) -> count[b] - count[a]);
        StringBuilder sb = new StringBuilder();
        for (char c : chars) for (int i = 0; i < count[c]; i++) sb.append(c);
        return sb.toString();
    }
}
