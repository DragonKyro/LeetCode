import java.util.*;

class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        Map<Integer, int[]> map = new HashMap<>();
        for (int i = 0; i < indices.length; i++) {
            if (s.startsWith(sources[i], indices[i]))
                map.put(indices[i], new int[]{sources[i].length(), i});
        }
        StringBuilder sb = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            if (map.containsKey(i)) {
                sb.append(targets[map.get(i)[1]]);
                i += map.get(i)[0];
            } else sb.append(s.charAt(i++));
        }
        return sb.toString();
    }
}
