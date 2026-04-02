import java.util.*;

class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> freq = new LinkedHashMap<>();
        for (String s : arr) freq.merge(s, 1, Integer::sum);
        int count = 0;
        for (String s : arr) {
            if (freq.get(s) == 1) {
                count++;
                if (count == k) return s;
            }
        }
        return "";
    }
}
