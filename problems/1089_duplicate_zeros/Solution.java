class Solution {
    public void duplicateZeros(int[] arr) {
        int zeros = 0;
        for (int a : arr) if (a == 0) zeros++;
        int n = arr.length, i = n - 1, j = n + zeros - 1;
        while (i < j) {
            if (arr[i] == 0) {
                if (j < n) arr[j] = 0;
                j--;
                if (j < n) arr[j] = 0;
            } else {
                if (j < n) arr[j] = arr[i];
            }
            i--; j--;
        }
    }
}
