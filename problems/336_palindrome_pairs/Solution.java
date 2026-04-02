import java.util.*;

class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < words.length; i++) map.put(words[i], i);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j <= words[i].length(); j++) {
                String prefix = words[i].substring(0, j);
                String suffix = words[i].substring(j);
                if (isPalin(prefix)) {
                    String rev = new StringBuilder(suffix).reverse().toString();
                    if (map.containsKey(rev) && map.get(rev) != i)
                        res.add(Arrays.asList(map.get(rev), i));
                }
                if (j != words[i].length() && isPalin(suffix)) {
                    String rev = new StringBuilder(prefix).reverse().toString();
                    if (map.containsKey(rev) && map.get(rev) != i)
                        res.add(Arrays.asList(i, map.get(rev)));
                }
            }
        }
        return res;
    }
    boolean isPalin(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) if (s.charAt(l++) != s.charAt(r--)) return false;
        return true;
    }
}
