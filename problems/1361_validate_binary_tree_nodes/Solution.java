import java.util.*;

class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        Set<Integer> children = new HashSet<>();
        for (int l : leftChild) if (l != -1) children.add(l);
        for (int r : rightChild) if (r != -1) children.add(r);
        int root = -1;
        for (int i = 0; i < n; i++) if (!children.contains(i)) { if (root != -1) return false; root = i; }
        if (root == -1) return false;
        Set<Integer> visited = new HashSet<>();
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited.add(node)) return false;
            if (leftChild[node] != -1) stack.push(leftChild[node]);
            if (rightChild[node] != -1) stack.push(rightChild[node]);
        }
        return visited.size() == n;
    }
}
