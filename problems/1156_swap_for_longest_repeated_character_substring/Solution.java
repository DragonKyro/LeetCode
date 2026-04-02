import java.util.*;

class Solution {
    public int maxRepOpt1(String text) {
        int[] count = new int[26];
        for (char c : text.toCharArray()) count[c - 'a']++;
        List<int[]> groups = new ArrayList<>();
        int i = 0;
        while (i < text.length()) {
            int j = i;
            while (j < text.length() && text.charAt(j) == text.charAt(i)) j++;
            groups.add(new int[]{text.charAt(i) - 'a', j - i});
            i = j;
        }
        int result = 0;
        for (int k = 0; k < groups.size(); k++) {
            int ch = groups.get(k)[0], len = groups.get(k)[1];
            result = Math.max(result, Math.min(len + 1, count[ch]));
            if (k + 2 < groups.size() && groups.get(k + 2)[0] == ch && groups.get(k + 1)[1] == 1) {
                result = Math.max(result, Math.min(len + groups.get(k + 2)[1] + 1, count[ch]));
            }
        }
        return result;
    }
}
