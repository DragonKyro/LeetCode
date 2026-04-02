import java.util.*;

class Solution {
    public String orderlyQueue(String s, int k) {
        if (k > 1) { char[] arr = s.toCharArray(); Arrays.sort(arr); return new String(arr); }
        String result = s;
        for (int i = 1; i < s.length(); i++) {
            String rot = s.substring(i) + s.substring(0, i);
            if (rot.compareTo(result) < 0) result = rot;
        }
        return result;
    }
}
