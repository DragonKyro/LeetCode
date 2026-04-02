class Solution {
    public int minimumDeletions(String s) {
        int bCount = 0, result = 0;
        for (char c : s.toCharArray()) {
            if (c == 'b') {
                bCount++;
            } else {
                result = Math.min(result + 1, bCount);
            }
        }
        return result;
    }
}
