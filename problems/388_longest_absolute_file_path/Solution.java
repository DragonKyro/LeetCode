import java.util.*;

class Solution {
    public int lengthLongestPath(String input) {
        Deque<Integer> stack = new ArrayDeque<>();
        int maxLen = 0;
        for (String line : input.split("\n")) {
            int level = line.lastIndexOf('\t') + 1;
            String name = line.substring(level);
            while (stack.size() > level) stack.pop();
            int length = (stack.isEmpty() ? 0 : stack.peek()) + name.length() + 1;
            stack.push(length);
            if (name.contains(".")) maxLen = Math.max(maxLen, length - 1);
        }
        return maxLen;
    }
}
