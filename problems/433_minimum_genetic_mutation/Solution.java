import java.util.*;

class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
        if (!bankSet.contains(endGene)) return -1;
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer(startGene);
        visited.add(startGene);
        int steps = 0;
        char[] genes = {'A','C','G','T'};
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int s = 0; s < size; s++) {
                String curr = queue.poll();
                if (curr.equals(endGene)) return steps;
                char[] arr = curr.toCharArray();
                for (int i = 0; i < 8; i++) {
                    char old = arr[i];
                    for (char c : genes) {
                        arr[i] = c;
                        String next = new String(arr);
                        if (bankSet.contains(next) && !visited.contains(next)) {
                            visited.add(next);
                            queue.offer(next);
                        }
                    }
                    arr[i] = old;
                }
            }
            steps++;
        }
        return -1;
    }
}
