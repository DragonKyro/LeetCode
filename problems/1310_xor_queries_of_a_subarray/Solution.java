class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] ^ arr[i];
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++)
            res[i] = prefix[queries[i][1]+1] ^ prefix[queries[i][0]];
        return res;
    }
}
