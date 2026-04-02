import java.util.*;

class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> order = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) order.put(arr2[i], i);
        return Arrays.stream(arr1).boxed()
            .sorted((a, b) -> {
                if (order.containsKey(a) && order.containsKey(b)) return order.get(a) - order.get(b);
                if (order.containsKey(a)) return -1;
                if (order.containsKey(b)) return 1;
                return a - b;
            }).mapToInt(Integer::intValue).toArray();
    }
}
