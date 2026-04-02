import java.util.*;

class Solution {
    public String simplifyPath(String path) {
        Deque<String> stack = new ArrayDeque<>();
        for (String part : path.split("/")) {
            if (part.equals("..")) { if (!stack.isEmpty()) stack.pop(); }
            else if (!part.isEmpty() && !part.equals(".")) stack.push(part);
        }
        StringBuilder sb = new StringBuilder();
        for (String s : stack) sb.insert(0, "/" + s);
        return sb.length() == 0 ? "/" : sb.toString();
    }
}
