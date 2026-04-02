class Solution {
    public int maxChunksToSorted(int[] arr) {
        int chunks = 0, max_so_far = 0;
        for (int i = 0; i < arr.length; i++) {
            max_so_far = Math.max(max_so_far, arr[i]);
            if (max_so_far == i) chunks++;
        }
        return chunks;
    }
}
