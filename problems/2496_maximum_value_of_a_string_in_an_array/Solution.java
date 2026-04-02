class Solution {
    public int maximumValue(String[] strs) {
        int result = 0;
        for (String s : strs) {
            try { result = Math.max(result, Integer.parseInt(s)); }
            catch (Exception e) { result = Math.max(result, s.length()); }
        }
        return result;
    }
}
