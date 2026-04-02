class Solution {
    public int maximumRemovals(String s, String p, int[] removable) {
        int lo = 0, hi = removable.length;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canRemove(s, p, removable, mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi;
    }
    private boolean canRemove(String s, String p, int[] removable, int k) {
        boolean[] removed = new boolean[s.length()];
        for (int i = 0; i < k; i++) removed[removable[i]] = true;
        int j = 0;
        for (int i = 0; i < s.length() && j < p.length(); i++) {
            if (!removed[i] && s.charAt(i) == p.charAt(j)) j++;
        }
        return j == p.length();
    }
}
