class Solution {
    public int longestDecomposition(String text) {
        int n = text.length();
        int result = 0;
        int left = 0, right = n - 1;
        String lStr = "", rStr = "";
        while (left < right) {
            lStr += text.charAt(left);
            rStr = text.charAt(right) + rStr;
            if (lStr.equals(rStr)) {
                result += 2;
                lStr = "";
                rStr = "";
            }
            left++;
            right--;
        }
        if (left == right || !lStr.isEmpty()) result++;
        return result;
    }
}
