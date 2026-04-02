import java.util.*;

class Solution {
    public List<Integer> pancakeSort(int[] arr) {
        List<Integer> result = new ArrayList<>();
        int n = arr.length;
        for (int size = n; size > 1; size--) {
            int maxIdx = 0;
            for (int i = 1; i < size; i++)
                if (arr[i] > arr[maxIdx]) maxIdx = i;
            if (maxIdx == size - 1) continue;
            if (maxIdx != 0) { result.add(maxIdx + 1); flip(arr, maxIdx); }
            result.add(size); flip(arr, size - 1);
        }
        return result;
    }
    private void flip(int[] arr, int k) {
        int i = 0;
        while (i < k) { int tmp = arr[i]; arr[i++] = arr[k]; arr[k--] = tmp; }
    }
}
