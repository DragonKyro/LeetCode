import java.util.*;

class Solution {
    public int countPalindromicSubsequence(String s) {
        int result = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.indexOf(c), last = s.lastIndexOf(c);
            if (last - first > 1) {
                Set<Character> set = new HashSet<>();
                for (int i = first + 1; i < last; i++) set.add(s.charAt(i));
                result += set.size();
            }
        }
        return result;
    }
}
