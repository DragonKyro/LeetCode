import java.util.*;

class Solution {
    public int numDifferentIntegers(String word) {
        Set<String> set = new HashSet<>();
        int i = 0, n = word.length();
        while (i < n) {
            if (Character.isDigit(word.charAt(i))) {
                int j = i;
                while (j < n && Character.isDigit(word.charAt(j))) j++;
                while (i < j - 1 && word.charAt(i) == '0') i++;
                set.add(word.substring(i, j));
                i = j;
            } else {
                i++;
            }
        }
        return set.size();
    }
}
