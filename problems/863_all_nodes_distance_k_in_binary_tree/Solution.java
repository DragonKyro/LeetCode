import java.util.*;

class Solution {
    Map<TreeNode, TreeNode> parent = new HashMap<>();
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        dfs(root, null);
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        queue.add(target); visited.add(target);
        int dist = 0;
        while (!queue.isEmpty()) {
            if (dist == k) {
                List<Integer> res = new ArrayList<>();
                for (TreeNode n : queue) res.add(n.val);
                return res;
            }
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                for (TreeNode nei : new TreeNode[]{node.left, node.right, parent.get(node)}) {
                    if (nei != null && visited.add(nei)) queue.add(nei);
                }
            }
            dist++;
        }
        return new ArrayList<>();
    }
    void dfs(TreeNode node, TreeNode par) {
        if (node == null) return;
        parent.put(node, par);
        dfs(node.left, node); dfs(node.right, node);
    }
}
