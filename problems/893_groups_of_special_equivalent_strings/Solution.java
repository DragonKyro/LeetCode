import java.util.*;

class Solution {
    public int numSpecialEquivGroups(String[] words) {
        Set<String> set = new HashSet<>();
        for (String w : words) {
            char[] even = new char[(w.length() + 1) / 2], odd = new char[w.length() / 2];
            for (int i = 0; i < w.length(); i++) {
                if (i % 2 == 0) even[i / 2] = w.charAt(i);
                else odd[i / 2] = w.charAt(i);
            }
            Arrays.sort(even); Arrays.sort(odd);
            set.add(new String(even) + new String(odd));
        }
        return set.size();
    }
}
