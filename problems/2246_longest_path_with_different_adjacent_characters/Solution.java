import java.util.*;

class Solution {
    int ans = 1;
    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        List<List<Integer>> children = new ArrayList<>();
        for (int i = 0; i < n; i++) children.add(new ArrayList<>());
        for (int i = 1; i < n; i++) children.get(parent[i]).add(i);
        dfs(0, children, s);
        return ans;
    }
    private int dfs(int node, List<List<Integer>> children, String s) {
        int top1 = 0, top2 = 0;
        for (int child : children.get(node)) {
            int len = dfs(child, children, s);
            if (s.charAt(child) != s.charAt(node)) {
                if (len > top1) { top2 = top1; top1 = len; }
                else if (len > top2) top2 = len;
            }
        }
        ans = Math.max(ans, top1 + top2 + 1);
        return top1 + 1;
    }
}
