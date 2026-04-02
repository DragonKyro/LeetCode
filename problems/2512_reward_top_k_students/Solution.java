import java.util.*;

class Solution {
    public List<Integer> topStudents(String[] pos, String[] neg, String[] report, int[] id, int k) {
        Set<String> p = new HashSet<>(Arrays.asList(pos)), n = new HashSet<>(Arrays.asList(neg));
        int[][] sc = new int[id.length][2];
        for (int i = 0; i < id.length; i++) {
            int score = 0;
            for (String w : report[i].split(" ")) { if (p.contains(w)) score += 3; else if (n.contains(w)) score -= 1; }
            sc[i] = new int[]{-score, id[i]};
        }
        Arrays.sort(sc, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k; i++) ans.add(sc[i][1]);
        return ans;
    }
}
