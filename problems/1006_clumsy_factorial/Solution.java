import java.util.*;

class Solution {
    public int clumsy(int n) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(n);
        n--;
        int idx = 0;
        while (n > 0) {
            switch (idx % 4) {
                case 0: stack.push(stack.pop() * n); break;
                case 1: stack.push(stack.pop() / n); break;
                case 2: stack.push(n); break;
                case 3: stack.push(-n); break;
            }
            idx++;
            n--;
        }
        int sum = 0;
        for (int v : stack) sum += v;
        return sum;
    }
}
