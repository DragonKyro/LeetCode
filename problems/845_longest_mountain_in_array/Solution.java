class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length, result = 0, i = 1;
        while (i < n - 1) {
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                int left = i, right = i;
                while (left > 0 && arr[left-1] < arr[left]) left--;
                while (right < n-1 && arr[right] > arr[right+1]) right++;
                result = Math.max(result, right - left + 1);
                i = right;
            } else i++;
        }
        return result;
    }
}
