class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++)
            if (!String.valueOf(a).contains("0") && !String.valueOf(n-a).contains("0"))
                return new int[]{a, n-a};
        return new int[]{};
    }
}
