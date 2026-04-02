import java.util.*;

class Solution {
    public int minDeletions(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        Arrays.sort(freq);
        int deletions = 0;
        Set<Integer> used = new HashSet<>();
        for (int i = 25; i >= 0; i--) {
            if (freq[i] == 0) continue;
            int f = freq[i];
            while (f > 0 && used.contains(f)) f--;
            deletions += freq[i] - f;
            if (f > 0) used.add(f);
        }
        return deletions;
    }
}
