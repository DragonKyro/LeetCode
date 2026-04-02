import java.util.*;

class Solution {
    Map<Integer, List<Integer>> graph = new HashMap<>();
    public int amountOfTime(TreeNode root, int start) {
        build(root, null);
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start); visited.add(start);
        int time = -1;
        while (!queue.isEmpty()) {
            time++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int node = queue.poll();
                for (int neighbor : graph.getOrDefault(node, List.of())) {
                    if (visited.add(neighbor)) queue.add(neighbor);
                }
            }
        }
        return time;
    }
    void build(TreeNode node, TreeNode parent) {
        if (node == null) return;
        if (parent != null) {
            graph.computeIfAbsent(node.val, k -> new ArrayList<>()).add(parent.val);
            graph.computeIfAbsent(parent.val, k -> new ArrayList<>()).add(node.val);
        }
        build(node.left, node); build(node.right, node);
    }
}
