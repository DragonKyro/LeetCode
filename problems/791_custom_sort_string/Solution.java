import java.util.*;

class Solution {
    public String customSortString(String order, String s) {
        int[] rank = new int[26];
        Arrays.fill(rank, 26);
        for (int i = 0; i < order.length(); i++) rank[order.charAt(i) - 'a'] = i;
        Character[] chars = new Character[s.length()];
        for (int i = 0; i < s.length(); i++) chars[i] = s.charAt(i);
        Arrays.sort(chars, (a, b) -> rank[a - 'a'] - rank[b - 'a']);
        StringBuilder sb = new StringBuilder();
        for (char c : chars) sb.append(c);
        return sb.toString();
    }
}
