class Solution {
    public int convertTime(String current, String correct) {
        int diff = toMin(correct) - toMin(current);
        int ops = 0;
        for (int d : new int[]{60, 15, 5, 1}) {
            ops += diff / d;
            diff %= d;
        }
        return ops;
    }
    private int toMin(String t) {
        return Integer.parseInt(t.substring(0, 2)) * 60 + Integer.parseInt(t.substring(3));
    }
}
