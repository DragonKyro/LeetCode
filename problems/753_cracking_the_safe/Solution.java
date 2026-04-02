import java.util.*;

class Solution {
    Set<String> seen = new HashSet<>();
    StringBuilder sb = new StringBuilder();

    public String crackSafe(int n, int k) {
        String start = String.join("", Collections.nCopies(n - 1, "0"));
        dfs(start, k);
        sb.append(start);
        return sb.toString();
    }

    private void dfs(String node, int k) {
        for (int x = 0; x < k; x++) {
            String nei = node + x;
            if (seen.add(nei)) {
                dfs(nei.substring(1), k);
                sb.append(x);
            }
        }
    }
}
